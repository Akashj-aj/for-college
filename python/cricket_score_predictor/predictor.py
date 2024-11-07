import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestRegressor

# Load dataset
dataset = pd.read_csv('ipl.csv')
X = dataset.iloc[:, [7, 8, 9, 12, 13]].values  # Modify as needed based on your dataset columns
y = dataset.iloc[:, 14].values  # Label

# Split dataset
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=0)

# Scale features
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)

# Train model
model = RandomForestRegressor(n_estimators=100, max_features=None)
model.fit(X_train, y_train)

# Define custom accuracy function
def custom_accuracy(y_test, y_pred, threshold):
    right = 0
    l = len(y_pred)
    for i in range(l):
        if abs(y_pred[i] - y_test[i]) <= threshold:
            right += 1
    return (right / l) * 100

# Evaluate model
y_pred = model.predict(X_test)
score = model.score(X_test, y_test) * 100
print("R-squared value:", score)
print("Custom accuracy:", custom_accuracy(y_test, y_pred, 10))

# Predict with user input
try:
    # Prompt user for input values
    print("Enter the values for prediction:")
    overs_completed = float(input("Overs Completed: "))
    wickets_down = int(input("Wickets Down: "))
    runs_last_5_overs = int(input("Runs in Last 5 Overs: "))
    wickets_last_5_overs = int(input("Wickets in Last 5 Overs: "))
    run_rate = float(input("Run Rate: "))

    # Make a prediction with user input
    user_input = np.array([[overs_completed, wickets_down, runs_last_5_overs, wickets_last_5_overs, run_rate]])
    user_input_scaled = sc.transform(user_input)
    new_prediction = model.predict(user_input_scaled)

    print("Prediction score:", new_prediction[0])
except ValueError:
    print("Invalid input! Please enter numerical values.")
