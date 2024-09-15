# Python function that accepts a sentence from the user and counts the number of words in the sentence.


def count_words(sentence):
    # Split the sentence into words using spaces as the delimiter
    words = sentence.split()
    # Return the number of words
    return len(words)

# Get the sentence from the user
user_sentence = input("Enter a sentence: ")

# Count the number of words in the sentence
word_count = count_words(user_sentence)

# Display the result
print("The number of words in the sentence is:", word_count)
