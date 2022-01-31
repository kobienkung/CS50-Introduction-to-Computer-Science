from cs50 import get_int
import re

num = 0
while True:
    num = get_int("Number: ")
    if len(str(num)) in [13, 15, 16]:
        break

numStr = str(num)
l = len(numStr)

def increment(n):
    total = 0
    while n > 0:
        a = n % 10
        n = int(n / 10)
        b = (n % 10) * 2
        n = int(n / 10)
        c = b % 10
        b = int(b / 10)
        total += a + b + c
    if total % 10 != 0:
        return False
    else:
        return True

if increment(num):
    if re.search('^34|37', numStr):# and l == 15:
        print('AMEX')
    elif re.search('^51|52|53|54|55', numStr) and l == 16:
        print('MASTERCARD')
    elif re.search('^4', numStr) and l in [13, 16]:
        print('VISA')
    else:
        print('INVALID')
else:
    print('INVALID')