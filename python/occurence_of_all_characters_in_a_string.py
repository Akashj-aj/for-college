
D = {}
S = input("Enter a string: ")

for ch in S:
    D[ch] = D.get(ch, 0) + 1

print(D)
