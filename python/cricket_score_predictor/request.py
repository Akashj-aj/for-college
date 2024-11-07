import request

url = 'http://127.0.0.1:5000/predict'
payload = {
    "Matches_Batted": 10,
    "Not_Outs": 2,
    "Batting_Average": 30.5,
    "Balls_Faced": 250,
    "Batting_Strike_Rate": 85.0,
    "Centuries": 1,
    "Half_Centuries": 3,
    "Fours": 20,
    "Sixes": 5,
    "Wickets_Taken": 10
}

# Make the request with the correct content type
headers = {'Content-Type': 'application/json'}
response = request.post(url, json=payload, headers=headers)

print(response.json())
