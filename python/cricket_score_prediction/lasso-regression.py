import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import Lasso
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score

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

# Initialize and train the Lasso Regression model with debug statement
print("Training Lasso Regression model...")
model = Lasso(alpha=0.1, random_state=0)  # Alpha is the regularization strength; adjust if needed
model.fit(X_train, y_train)
print("Model training completed.")

# Define custom accuracy function for predictions within a specified threshold (e.g., 10 runs)
def custom_accuracy(y_test, y_pred, threshold):
    within_threshold = [1 for actual, pred in zip(y_test, y_pred) if abs(actual - pred) <= threshold]
    accuracy = (sum(within_threshold) / len(y_test)) * 100
    return accuracy

# Predict and evaluate model
y_pred = model.predict(X_test)
r2 = r2_score(y_test, y_pred) * 100
mae = mean_absolute_error(y_test, y_pred)
mse = mean_squared_error(y_test, y_pred)
rmse = mse ** 0.5  # Root Mean Squared Error
custom_acc = custom_accuracy(y_test, y_pred, threshold=10)

# Print evaluation metrics
print("R-squared value:", r2)
print("Mean Absolute Error (MAE):", mae)
print("Mean Squared Error (MSE):", mse)
print("Root Mean Squared Error (RMSE):", rmse)
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
