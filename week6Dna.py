from sys import argv
import csv


if len(argv) != 3:
    print('Incorrect input')
    exit()


with open(argv[2]) as textFile:
    obj = textFile.read()
    for row in obj:
        text = obj
#print(text)


database = []
with open(argv[1]) as csvFile:
    obj = csv.reader(csvFile)
    for row in obj:
        database.append(row)
#print(database)


ident = dict()
for code in database[0]:
    for i in range(len(text)):
        if text[i] == code[0]:
            n = i + 1
            c = 1
            countTem = 0
            while n < len(text) and text[n] == code[c]:
                n += 1
                c += 1
                if c == (len(code)):
                    c = 0
                    i = n
                    countTem += 1
            if code not in ident : ident[code] = countTem
            if countTem > ident[code]:
                ident[code] = countTem

#print(ident)

found = False
for obj in database:
    for i in range(1, len(obj)):
        if not obj[i] == str(ident[database[0][i]]):
            break
        if i == len(obj) - 1:
            found = True
            print(obj[0])
            break

if not found:
    print('No match')