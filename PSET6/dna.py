# import libraries
from sys import argv, exit
from csv import reader, DictReader

# make sure that there are three command line aruguments
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequences.txt")
    exit(1)

# open the csv file for reading and read the file
csvFile = open(argv[1], newline='')
csvReader = reader(csvFile)
firstRow = next(csvReader)

# open the txt file for reading and read the file
with open(argv[2], newline='') as txtFile:
    txtReader = txtFile.read()

counter = []  # create an empty array to store the STR

# iterates through the STRs listed in the first row of the csv file
for i in range(1, len(firstRow)):
    occurance = 0
    n = 1

    # find the most occurances of each STR by incrementing n
    while firstRow[i]*n in txtReader:
        n += 1

    if (n - 1) > occurance:
        occurance = n - 1  # minus the 1 from n when n was set to 1
    counter.append(occurance)  # append the occurances to the list

found = False

# iterates through every row in the csv file
for row in csvReader:
    match = 0

    # iterates through every element in the list
    for j in range(len(counter)):

        # if the element is found in the row of the file, increase match
        if int(counter[j]) == int(row[j + 1]):
            match += 1

    # if every element in the counter is found, print the name
    if match == len(counter):
        print(row[0])
        found = True

if found == False:
    print("No match")

# close the files
txtFile.close()
csvFile.close()