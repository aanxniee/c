# import libraries
from sys import argv
import csv
from cs50 import SQL

# ensure that there are 2 command line arguments
if len(argv) != 2:
    print("Usage: import.py file.csv")
    exit()

# open the database file and store it in a variable
db = SQL("sqlite:///students.db")

file = argv[1]
# open the csv file for reading
with open(file, newline='') as characters:
    characterReader = csv.DictReader(characters)

    # iterate through each row in the csv file and copy the content into a list
    for row in characterReader:
        # parse the name into first, middle, last
        name = row['name'].split()

        if len(name) == 2:
            firstName = name[0]
            middleName = None
            lastName = name[1]

        elif len(name) == 3:
            firstName = name[0]
            middleName = name[1]
            lastName = name[2]

        house = row['house']
        birth = row['birth']

        # insert the information into the table
        db.execute("INSERT INTO students ('first', 'middle', 'last', 'house', 'birth') VALUES (?, ?, ?, ?, ?)",
                   firstName, middleName, lastName, house, birth)
