import requests

def check_football_matches():
		url = "https://livescore6.p.rapidapi.com/matches/v2/list-live"

		querystring = {"Category":"soccer","Timezone":"-7"}

		headers = {
			"X-RapidAPI-Key": "2f9f0814f8msh33e55ded60e9f41p15d3f2jsn195a6b4d31e8",
			"X-RapidAPI-Host": "livescore6.p.rapidapi.com"
		}

		response = requests.get(url, headers=headers, params=querystring)
		return response.json()

def check_cricket_matches():
		url = "https://livescore6.p.rapidapi.com/matches/v2/list-live"

		querystring = {"Category":"cricket","Timezone":"-7"}

		headers = {
			"X-RapidAPI-Key": "2f9f0814f8msh33e55ded60e9f41p15d3f2jsn195a6b4d31e8",
			"X-RapidAPI-Host": "livescore6.p.rapidapi.com"
		}

		response = requests.get(url, headers=headers, params=querystring)
		return response.json()

def check_basketball_matches():
		url = "https://livescore6.p.rapidapi.com/matches/v2/list-live"

		querystring = {"Category":"basketball","Timezone":"-7"}

		headers = {
			"X-RapidAPI-Key": "2f9f0814f8msh33e55ded60e9f41p15d3f2jsn195a6b4d31e8",
			"X-RapidAPI-Host": "livescore6.p.rapidapi.com"
		}

		response = requests.get(url, headers=headers, params=querystring)
		return response.json()


def check_hockey_matches():
		url = "https://livescore6.p.rapidapi.com/matches/v2/list-live"

		querystring = {"Category":"hockey","Timezone":"-7"}

		headers = {
			"X-RapidAPI-Key": "2f9f0814f8msh33e55ded60e9f41p15d3f2jsn195a6b4d31e8",
			"X-RapidAPI-Host": "livescore6.p.rapidapi.com"
		}

		response = requests.get(url, headers=headers, params=querystring)
		return response.json()


def check_tennis_matches():
		url = "https://livescore6.p.rapidapi.com/matches/v2/list-live"

		querystring = {"Category":"tennis","Timezone":"-7"}

		headers = {
			"X-RapidAPI-Key": "2f9f0814f8msh33e55ded60e9f41p15d3f2jsn195a6b4d31e8",
			"X-RapidAPI-Host": "livescore6.p.rapidapi.com"
		}

		response = requests.get(url, headers=headers, params=querystring)
		return response.json()


def check_hockey_date(date):

		url = "https://livescore6.p.rapidapi.com/matches/v2/list-by-date"

		querystring = {"Category":"hockey","Date":date,"Timezone":"-7"}

		headers = {
			"X-RapidAPI-Key": "2f9f0814f8msh33e55ded60e9f41p15d3f2jsn195a6b4d31e8",
			"X-RapidAPI-Host": "livescore6.p.rapidapi.com"
		}

		response = requests.get(url, headers=headers, params=querystring)

		return response.json()

def check_football_date(date):

		url = "https://livescore6.p.rapidapi.com/matches/v2/list-by-date"

		querystring = {"Category":"soccer","Date":date,"Timezone":"-7"}

		headers = {
			"X-RapidAPI-Key": "2f9f0814f8msh33e55ded60e9f41p15d3f2jsn195a6b4d31e8",
			"X-RapidAPI-Host": "livescore6.p.rapidapi.com"
		}

		response = requests.get(url, headers=headers, params=querystring)

		return response.json()
def check_cricket_date(date):

		url = "https://livescore6.p.rapidapi.com/matches/v2/list-by-date"

		querystring = {"Category":"cricket","Date":date,"Timezone":"-7"}

		headers = {
			"X-RapidAPI-Key": "2f9f0814f8msh33e55ded60e9f41p15d3f2jsn195a6b4d31e8",
			"X-RapidAPI-Host": "livescore6.p.rapidapi.com"
		}

		response = requests.get(url, headers=headers, params=querystring)

		return response.json()

def check_basketball_date(date):

		url = "https://livescore6.p.rapidapi.com/matches/v2/list-by-date"

		querystring = {"Category":"basketball","Date":date,"Timezone":"-7"}

		headers = {
			"X-RapidAPI-Key": "2f9f0814f8msh33e55ded60e9f41p15d3f2jsn195a6b4d31e8",
			"X-RapidAPI-Host": "livescore6.p.rapidapi.com"
		}

		response = requests.get(url, headers=headers, params=querystring)

		return response.json()

def check_tennis_date(date):

		url = "https://livescore6.p.rapidapi.com/matches/v2/list-by-date"

		querystring = {"Category":"tennis","Date":date,"Timezone":"-7"}

		headers = {
			"X-RapidAPI-Key": "2f9f0814f8msh33e55ded60e9f41p15d3f2jsn195a6b4d31e8",
			"X-RapidAPI-Host": "livescore6.p.rapidapi.com"
		}

		response = requests.get(url, headers=headers, params=querystring)

		return response.json()
