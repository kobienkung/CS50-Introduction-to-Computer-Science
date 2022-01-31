from cs50 import get_int

height = 0
while True:
    height = get_int("Height: ")
    if height in range(1, 9):
        break

def block(h):
    if h > 1:
        block(h -1)
    print(' ' * (height - h) + '#' * h + '  ' + '#' * h)

block(height)