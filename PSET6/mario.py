# import libraries
from cs50 import get_int

# ask the user for the height
height = get_int("Height: ")

# ensure that the height is between 1 and 8
while height < 1 or height > 8:
    height = get_int("Height: ")

# this loop prints each row until the desired height is reaches
for i in range(1, height + 1):

    for j in range(1, height + 1):
        # this prints the black space with one less in reach row
        if (j <= height - i):
            print(" ", end="")
        # this prints the # with one more in each row
        else:
            print("#", end="")

    # skip to the next line
    print()