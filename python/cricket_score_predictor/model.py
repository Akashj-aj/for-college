import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split

class CricketScorePredictor:
    def __init__(self, csv_file):
        self.data = pd.read_csv(csv_file)
        self.data.replace('No stats', 0, inplace=True)  # Replace 'No stats' with 0
        self.data = self.data.apply(pd.to_numeric, errors='ignore')  # Convert columns to numeric, ignore non-numeric
        self.model = LinearRegression()
        self.train_model()

    def train_model(self):
        # Select features and target variable
        X = self.data[['Matches_Batted', 'Not_Outs', 'Batting_Average', 
                       'Balls_Faced', 'Batting_Strike_Rate', 'Centuries', 
                       'Half_Centuries', 'Fours', 'Sixes', 
                       'Wickets_Taken']]  # Use relevant features
        y = self.data['Runs_Scored']  # Target variable

        # Remove rows with NaN values after replacement
        X = X.dropna()
        y = y[X.index]  # Align the target variable with the feature set

        # Split the data into training and testing sets
        X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
        
        # Train the model
        self.model.fit(X_train, y_train)

    def predict_score(self, matches_batted, not_outs, batting_average, balls_faced, 
                      batting_strike_rate, centuries, half_centuries, fours, 
                      sixes, wickets_taken):
        # Prepare the input data as a DataFrame
        input_data = pd.DataFrame({
            'Matches_Batted': [matches_batted],
            'Not_Outs': [not_outs],
            'Batting_Average': [batting_average],
            'Balls_Faced': [balls_faced],
            'Batting_Strike_Rate': [batting_strike_rate],
            'Centuries': [centuries],
            'Half_Centuries': [half_centuries],
            'Fours': [fours],
            'Sixes': [sixes],
            'Wickets_Taken': [wickets_taken]
        })
        
        # Make a prediction
        predicted_score = self.model.predict(input_data)[0]
        
        return predicted_score
