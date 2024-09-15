# Python program to store phone numbers of persons in a dictionary and display the phone number of the requested person. 

# Create an empty dictionary to store name-phone number pairs
D = {}

# Get the total number of persons from the user
n = int(input("Enter the total no of persons: "))

# Read names and phone numbers and store them in the dictionary
for i in range(n):
    name = input("Enter the name: ")
    ph = int(input("Enter the phone number: "))
    D[name] = ph

# Print the dictionary containing all the name-phone number pairs
print(D)

# Get the name to search for from the user
name = input("Enter the name of person to search for ph no: ")

# Search for the phone number using the get method, providing a default value if the name is not found
ph = D.get(name, "does not exist")

# Print the found phone number or the "does not exist" message
print("Phone number:", ph)