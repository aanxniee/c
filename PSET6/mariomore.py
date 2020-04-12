# import libraries
from cs50 import get_int

# prompt the user to enter a height
height = get_int("Height: ")

# ensure that the height is between 1 and 8
while height < 1 or height > 8:
    height = get_int("Height: ")

width = height  # set the width equal to the height

# this loop prints each row until the desired height is reaches
for i in range(1, height + 1):
    space = width - i

    print(" " * space, end="")  # print the space with one less each line
    print("#" * i, end="")  # print the # with one more each line for the first pyramid
    print("  ", end="")  # print the double spacing between the 2 pyramids
    print("#" * i)  # print the # with one more each line for the second pyramid