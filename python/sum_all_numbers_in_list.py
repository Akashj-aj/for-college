# Write a Python program to sum all the numbers in a list.

# Initialize an empty list to store the elements
L = []

# Get the total number of elements from the user
n = int(input("Enter total number of elements: "))

# Read and append elements to the list
for i in range(n):
    val = int(input("Enter the next element: "))
    L.append(val)

# Print the list of elements
print(L)

# Calculate and print the sum of the elements
print("Sum of all elements is:", sum(L))

# Calculate and print the average of the elements
print("Average of all elements is:", sum(L) / len(L))