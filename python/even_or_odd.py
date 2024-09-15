def check(a):
    return a % 2  # Returns the remainder of a divided by 2

n = int(input("Enter a number: "))

if check(n):
    print("odd")
else:
    print("even")