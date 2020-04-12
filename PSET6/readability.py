# import libraries
from cs50 import get_string
import math

# set variables as floats
letter = 0.0
word = 0.0
sentence = 0.0
grade = 0.0

text = get_string("Text: ")  # prompt the user to enter the text
length = len(text)  # find the length of the next

if text[0].isalnum():  # if the first letter of the character of text is alphanumeric, it is a word
    word = 1

for i in range(length):

    if text[i].isalnum():  # if the character is alphanumeric, it is a letter
        letter += 1

    # if there is a whitespace and the character after it is a alphanumeric, it is a word
    if i < length - 1 and text[i].isspace() and (text[i + 1].isalnum() or text[1 + 2].isalnum()):
        word += 1

    # if there is an ending punctuation and the character before it is alphanumeric, it is a sentence
    if i > 0 and (text[i] == '!' or text[i] == '?' or text[i] == '.') and text[i - 1].isalnum():
        sentence += 1

# calculate the grade using the formula
grade = round(0.0588 * (100 * letter / word) - 0.296 * (100 * sentence / word) - 15.8)

# display results
if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print("Grade", int(grade))