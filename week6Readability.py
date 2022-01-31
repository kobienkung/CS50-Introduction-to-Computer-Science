# from ctype import isalpha

text = input('Text: ')

def letCount(t):
    count = 0
    for let in t:
        if let.isalpha():
            count = count + 1
    return count

def wordCount(t):
    count = 0
    words = t.split()
    for word in words:
        count += 1
    return count

def senCount(t):
    count = 0
    for let in t:
        if let == '.' or let == '?' or let == '!':
            count += 1
    return count

W = wordCount(text)
L = letCount(text) * 100 / W
S = senCount(text) * 100 / W
G = 0.0588 * L - 0.296 * S - 15.8


if G > 16:
    G = 'Grade 16+'
    print(G)
elif G < 1:
    G = 'Before Grade 1'
    print(G)
else:
    G = round(G)
    print('Grade ' + str(G))
