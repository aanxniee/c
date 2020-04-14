# import libraries
from sys import argv
from cs50 import SQL

# ensure that there are 2 command line arguments
if len(argv) != 2:
    print("Usage: file.py houseName")
    exit()

# create a variable to stores the users input
houseName = argv[1].lower()
# create a list of all the possible houses
houses = ['gryffindor', 'hufflepuff', 'slytherin', 'ravenclaw']

# if the users input is not in the list, display error message
if houseName not in houses:
    print("Provide house name: Gryffindor, Hufflepuff, Slytherin, Ravenclaw")
    exit()

# open the data base file and store it in a variable
db = SQL("sqlite:///students.db")
# execute a query to display the names and births of the students in the selected house
# order the students by last then first name
roster = db.execute("SELECT first, middle, last, birth FROM students WHERE lower(house) = (?) ORDER BY last, first", houseName)

# iterate through each row of students
for row in roster:
    # display the students name and birth
    if row['middle'] == None:
        print("{} {}, born {}".format(row['first'], row['last'], row['birth']))
    else:
        print("{} {} {}, born {}".format(row['first'], row['middle'], row['last'], row['birth']))
