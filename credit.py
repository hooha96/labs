from cs50 import get_int
from sys import exit
import math

def main():
    num = get_int("Number: ")
    l = math.floor(math.log10(num)) + 1
    d = digit_check(num, l)

    # Checks if AMEX Card
    if (l == 15 and (d == 34 or d == 37)):
        if (luhn(num, l, d) == True):
            print("AMEX")
            exit(0)
        else:
            print("INVALID")

    # Checks if MASTERCARD
    if (l == 16 and (d == 51 or d == 52 or d == 53 or d == 54 or d == 55)):
        if (luhn(num, l, d) == True):
            print("MASTERCARD")
            exit(0)
        else:
            print("INVALID")

    # Checks if VISA Card
    if (((l == 13 or l == 16) and (math.floor(d / 10) == 4))):
        if (luhn(num, l, d) == True):
            print("VISA")
            exit(0)
        else:
            print("INVALID")

    print("INVALID")
    exit(0)

def digit_check(num, l):

    digit = num

    for i in range(0, l - 2, 1):
        digit = math.floor(digit / 10)

    d = digit

    return d

def luhn(num, l, d):
    n = num
    summ = 0
    sum_digits = 0
    digits = [0]*l
    temp = [0]*l

    for i in range(l - 1, -1, -1):
        digits[i] = math.floor(n % 10)
        n = n / 10

    for z in range(0, l, 1):
        temp[z] = digits[z]

    for x in range(l - 2, -1, -2):
        temp[x] = digits[x] * 2

    for y in range(l - 1, -1, -2):
        temp[y] = 0

    for q in range(0, l, 1):
        if temp[q] > 9:
            summ = summ + (math.floor(temp[q] / 10) + (temp[q] % 10))
        else:
            summ = summ + temp[q]

    for j in range(l - 1, -1, -2):
        sum_digits = sum_digits + digits[j]

    sum_total = summ + sum_digits

    if sum_total % 10 == 0:
        return True
    else:
        return False

main()
