import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    list = []
    grandtotal = 0
    holding = db.execute("SELECT * FROM holding WHERE user_id = ?", session["user_id"])
    for i in holding:
        value = lookup(i["stock"])
        total = int(i["share"]) * value["price"]

        value["share"] = i["share"]
        value["total"] = total
        list.append(value)

        grandtotal += total

    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
    grandtotal += float(cash[0]["cash"])
    return render_template("index.html", list=list, total=usd(grandtotal), cash=usd(cash[0]["cash"]))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")
    else:
        symbol = request.form.get("symbol")
        if symbol == "":
            return apology("Enter Stock Name", 400)

        value = lookup(symbol)
        if value == None:
            return apology("Enter Valid ticker symbol", 400)

        shares = request.form.get("shares")
        if not shares.isdigit() or int(shares) < 0:
            return apology("Enter valid value", 400)

        totalprice = float(shares) * float(value["price"])

        usercash = db.execute(
            "SELECT cash FROM users WHERE id = ?", session["user_id"]
        )
        if totalprice > float(usercash[0]["cash"]):
            return apology("You can't afford it ", 400)

        now = datetime.now()
        date = now.strftime("%x")
        time = now.strftime("%X")
        db.execute("INSERT INTO transactions(user_id, stock, share, status, date, time,price) VALUES(?, ?, ?, ?, ?, ?,?)",
                   session["user_id"], symbol, shares, "buy", date, time, value["price"])

        rows = db.execute(
            "SELECT * FROM holding WHERE user_id = ? AND stock = ?", session["user_id"], symbol
        )
        if len(rows) == 0:
            db.execute(
                "INSERT INTO holding(user_id, stock, share) VALUES(?,?,?)", session["user_id"], symbol, shares
            )
        else:
            # updating holding
            shares = int(shares) + int(rows[0]["share"])
            db.execute(
                "UPDATE holding SET share = ? WHERE user_id = ?", shares, session["user_id"]
            )

        usercash = float(usercash[0]["cash"]) - totalprice
        db.execute(
            "UPDATE users SET cash = ? WHERE id = ?", usercash, session["user_id"]
        )
        flash("Bought!")
        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # passing transactions list
    list = db.execute(
        "SELECT * FROM transactions WHERE user_id = ?", session["user_id"]
    )
    return render_template("history.html", list=list)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    else:
        symbol = request.form.get("symbol")
        if symbol == "":
            return apology("Enter Stock Name", 400)
        value = lookup(symbol)
        if value == None:
            return apology("Enter Valid ticker symbol", 400)

        return render_template("quoted.html", symbol=value["symbol"], name=value["name"], price=usd(value["price"]))


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    usernames = db.execute("SELECT username FROM users")
    username = request.form.get("username")
    password = request.form.get("password")
    confirmation = request.form.get("confirmation")
    if request.method == "GET":
        return render_template("register.html")

    else:
        if username == "":
            return apology("Please Insert the Username", 400)
        elif {"username": username} in usernames:
            return apology("Username is already taken", 400)
        elif password != confirmation:
            return apology("Password does not match", 400)
        elif password == "":
            return apology("Please Insert the password", 400)
        else:
            # generating hash
            hash = generate_password_hash(
                password, method="pbkdf2:sha256", salt_length=8
            )
            db.execute("INSERT INTO users(username, hash) VALUES(?, ?)", username, hash)

        return redirect("/")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "GET":
        stockname = db.execute("SELECT stock FROM holding WHERE user_id = ?", session["user_id"])
        return render_template("sell.html", list=stockname)
    else:
        symbol = request.form.get("symbol")
        if symbol is None:
            return apology("Enter Stock Name", 400)

        shares = request.form.get("shares")
        if not shares.isdigit() or int(shares) < 0:
            return apology("Enter valid count of shares", 400)

        # to check if share is not more than user actually holding
        share_count = db.execute(
            "SELECT share FROM holding WHERE user_id = ? AND stock = ?", session["user_id"], symbol
        )

        if int(shares) > int(share_count[0]["share"]):
            return apology("You don't own this much", 400)

        updatedshare = int(share_count[0]["share"]) - int(shares)
        if updatedshare == 0:
            db.execute(
                "DELETE FROM holding WHERE user_id = ? AND stock = ?", session["user_id"], symbol
            )
        else:
            db.execute(
                "UPDATE holding SET share = ? WHERE user_id = ? AND stock = ?", updatedshare, session["user_id"], symbol
            )

        value = lookup(symbol)
        usercash = db.execute(
            "SELECT cash FROM users WHERE id = ?", session["user_id"]
        )

        updatedcash = float(usercash[0]["cash"]) + (int(shares) * float(value["price"]))

        db.execute(
            "UPDATE users SET cash = ? WHERE id = ?", updatedcash, session["user_id"]
        )

        now = datetime.now()
        date = now.strftime("%x")
        time = now.strftime("%X")
        db.execute(
            "INSERT INTO transactions(user_id, stock, share, status, date, time,price) VALUES(?, ?, ?, ?, ?, ?,?)",
            session["user_id"], symbol, shares, "sell", date, time, value["price"]
        )
        flash("SOLD!")
        return redirect("/")
