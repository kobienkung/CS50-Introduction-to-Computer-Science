from cs50 import SQL
import csv
from sys import argv


if len(argv) != 2:
    print('error')
    exit()


open('students.db', 'w').close()


db = SQL('sqlite:///students.db')
db.execute('CREATE TABLE charactors (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)')


with open(argv[1]) as csvFile:
    row = csv.DictReader(csvFile)
    for obj in row:
        name = obj['name'].split()
        if len(name) == 2:
            first = name[0]
            middle = None
            last = name[1]
        else:
            first = name[0]
            middle = name[1]
            last = name[2]
        #print(first, middle, last)
        house = obj['house']
        birth = obj['birth']
        db.execute('INSERT INTO charactors (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)', first, middle, last, house, birth)