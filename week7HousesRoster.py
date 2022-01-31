from sys import argv
from cs50 import SQL


if len(argv) != 2:
    print('error')
    exit()


db = SQL('sqlite:///students.db')
charactors = db.execute('SELECT * FROM charactors WHERE house = ? ORDER BY last, first', argv[1])
for obj in charactors:
    if obj['middle'] != None:
        print(obj['FIRST'] + ' ' + obj['middle'] + ' ' + obj['LAST'] + ', born ' + str(obj['birth']))
    else:
        print((obj['FIRST'] + ' ' + obj['LAST'] + ', born ' + str(obj['birth'])))