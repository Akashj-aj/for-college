from flask import Flask, request, jsonify
from model import CricketScorePredictor

app = Flask(__name__)
predictor = CricketScorePredictor('scores.csv')

@app.route('/predict', methods=['POST'])
def predict():
    try:
        # Expecting JSON data
        data = request.get_json()

        # Extracting parameters from the JSON
        matches_batted = data.get('Matches_Batted')
        not_outs = data.get('Not_Outs')
        batting_average = data.get('Batting_Average')
        balls_faced = data.get('Balls_Faced')
        batting_strike_rate = data.get('Batting_Strike_Rate')
        centuries = data.get('Centuries')
        half_centuries = data.get('Half_Centuries')
        fours = data.get('Fours')
        sixes = data.get('Sixes')
        wickets_taken = data.get('Wickets_Taken')

        # Making prediction
        predicted_score = predictor.predict_score(matches_batted, not_outs, batting_average, balls_faced,
                                                  batting_strike_rate, centuries, half_centuries, fours,
                                                  sixes, wickets_taken)

        # Return the prediction as JSON
        return jsonify({'predicted_score': predicted_score})

    except Exception as e:
        return jsonify({'error': str(e)}), 400

if __name__ == '__main__':
    app.run(debug=True)
