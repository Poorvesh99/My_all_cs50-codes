from flask import Flask, flash, redirect, render_template, request, session
from helper import check_football_matches,check_cricket_matches,check_basketball_matches,check_hockey_matches,check_tennis_matches,check_hockey_date,check_football_date,check_cricket_date,check_basketball_date,check_tennis_date

#configuring application
app = Flask(__name__)

@app.route("/")
def football():
    ### giving back dated schedule
    date = request.args.get("date")
    if date:
        date1 = date[0:4]+date[5:7]+date[8:]
        key = check_football_date(date1)
        if len(key['Stages']) > 0:
            live = True
        else:
            live = False
        return render_template("football.html",key=key['Stages'],live = live,date=date)

    key = check_football_matches()
    if len(key['Stages']) > 0:
        live = True
    else:
        live = False
    return render_template("football.html",key=key['Stages'],live = live,date="Live")

@app.route("/cricket")
def cricket():
    ### giving back dated schedule
    date = request.args.get("date")
    if date:
        date1 = date[0:4]+date[5:7]+date[8:]
        key = check_cricket_date(date1)
        if len(key['Stages']) > 0:
            live = True
        else:
            live = False
        return render_template("cricket.html",key=key['Stages'],live = live,date=date)

    key = check_cricket_matches()
    if len(key['Stages']) > 0:
        live = True
    else:
        live = False
    return render_template("cricket.html",key=key['Stages'],live = live,date="Live")

@app.route("/basketball")
def basketball():
    ### giving back dated schedule
    date = request.args.get("date")
    if date:
        date1 = date[0:4]+date[5:7]+date[8:]
        key = check_basketball_date(date1)
        if len(key['Stages']) > 0:
            live = True
        else:
            live = False
        return render_template("basketball.html",key=key['Stages'],live = live,date=date)

    key = check_basketball_matches()
    if len(key['Stages']) > 0:
        live = True
    else:
        live = False
    return render_template("basketball.html",key=key['Stages'],live = live,date="Live")

@app.route("/hockey")
def hockey():
    ### giving back dated schedule
    date = request.args.get("date")
    if date:
        date1 = date[0:4]+date[5:7]+date[8:]
        key = check_hockey_date(date1)
        if len(key['Stages']) > 0:
            live = True
        else:
            live = False
        return render_template("hockey.html",key=key['Stages'],live = live,date=date)

    key = check_hockey_matches()
    if len(key['Stages']) > 0:
        live = True
    else:
        live = False



    return render_template("hockey.html",key=key['Stages'],live = live,date="Live")


@app.route("/tennis")
def tennis():
    ### giving back dated schedule
    date = request.args.get("date")
    if date:
        date1 = date[0:4]+date[5:7]+date[8:]
        key = check_tennis_date(date1)
        if len(key['Stages']) > 0:
            live = True
        else:
            live = False
        return render_template("tennis.html",key=key['Stages'],live = live,date=date)

    key = check_tennis_matches()
    if len(key['Stages']) > 0:
        live = True
    else:
        live = False


    return render_template("tennis.html",key=key['Stages'],live = live,date="Live")
