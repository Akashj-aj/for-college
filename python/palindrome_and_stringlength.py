# Write a Python program to calculate the length of a string without using built in function and check whether it is a palindrome or not. 

def calculate_length(s):
    count = 0
    for char in s:
        count += 1
    return count

def is_palindrome(s):
    length = calculate_length(s)
    for i in range(length // 2):
        if s[i] != s[length - i - 1]:
            return False
    return True

# Input string
input_string = input("Enter a string: ")

# Calculate length
length = calculate_length(input_string)
print("The length of the string is: ",length)

# Check if the string is a palindrome
if is_palindrome(input_string):
    print("The string is a palindrome.")
else:
    print("The string is not a palindrome.")
