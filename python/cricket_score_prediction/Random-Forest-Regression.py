import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import r2_score

# Load dataset with debug statement
try:
    dataset = pd.read_csv('ipl_match_data_with_wickets.csv')
    print("Dataset loaded successfully.")
except FileNotFoundError:
    print("Error: Dataset file not found. Ensure 'ipl_match_data_with_wickets.csv' is in the correct directory.")
    exit()

# Add relevant features for improved prediction
dataset['remaining_overs'] = 20 - dataset['Overs Played']  # Adjust if not T20
dataset['projected_score'] = dataset['Runs Scored'] + (dataset['remaining_overs'] * dataset['Run Rate'])

# Define input features and target variable
X = dataset[['Overs Played', 'Wickets Taken', 'Runs Scored', 'Run Rate', 'remaining_overs', 'projected_score']].values
y = dataset['Total Score in 20 Overs'].values  # Assuming 'Total Score in 20 Overs' is the target column

# Debug statement for features and target extraction
print("Features and target extracted.")

# Split data into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=0)

# Feature scaling
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)
print("Data scaled.")

# Initialize and train the model with debug statement
print("Training model...")
model = RandomForestRegressor(n_estimators=100, max_features=None, random_state=0)
model.fit(X_train, y_train)
print("Model training completed.")

# Define custom accuracy function
def custom_accuracy(y_test, y_pred, threshold):
    right = 0
    total = len(y_pred)
    for i in range(total):
        if abs(y_pred[i] - y_test[i]) <= threshold:
            right += 1
    return (right / total) * 100

# Predict and evaluate model
y_pred = model.predict(X_test)
r2 = r2_score(y_test, y_pred) * 100
custom_acc = custom_accuracy(y_test, y_pred, threshold=10)

print("R-squared value:", r2)
print("Custom accuracy (within 10 runs):", custom_acc)

# Take user input for prediction
print("\n--- Sample Prediction ---")
try:
    overs_played = float(input("Enter Overs Played: "))
    wickets_down = int(input("Enter Wickets Down: "))
    runs_scored = int(input("Enter Runs Scored: "))
    run_rate = float(input("Enter Current Run Rate: "))

    # Check if 20 overs are played or 10 wickets are down
    if overs_played == 20 or wickets_down == 10:
        # If 20 overs played or 10 wickets down, set predicted score to runs scored
        predicted_score = runs_scored
        print(f"Predicted Final Score: {predicted_score}")
    else:
        # Calculate remaining overs and projected score based on input
        remaining_overs = 20 - overs_played  # for T20 match
        projected_score = runs_scored + (remaining_overs * run_rate)

        # Prepare input data with the new features
        user_input = [[overs_played, wickets_down, runs_scored, run_rate, remaining_overs, projected_score]]
        user_input_scaled = sc.transform(user_input)  # Scale user input

        # Predict using the trained model
        predicted_score = model.predict(user_input_scaled)
        print(f"Predicted Final Score: {round(predicted_score[0])}")
except ValueError:
    print("Invalid input. Please enter numeric values only.")
