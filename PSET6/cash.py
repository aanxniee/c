# import libraries
from cs50 import get_float
from math import floor

cents = 0
count = 0
amount_left = 0

# ask the user to input their change
amount = get_float("Changed owed: ")

# ensures that the value is positive
while amount <= 0:
    amount = get_float("Changed owed: ")

# convert dollars to cents
cents = floor(amount * 100)

# counts the number of quarters
amount_left = cents
count += floor(amount_left / 25)
amount_left %= 25

# counts the number of dimes
count += floor(amount_left / 10)
amount_left %= 10

# counts the number of nickes
count += floor(amount_left / 5)
amount_left %= 5

# counts the number of pennies
count += floor(amount_left)

print(f"You get {int(count)} coins")
