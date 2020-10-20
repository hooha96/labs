from cs50 import get_int

# checks to see if input is valid, i.e between 1 and 8 inclusive
while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break

# prints the right-aligned half pyramid
j = height-1
for i in range(1, height+1, 1):
    print((j * " ") + (i * "#"))
    j -= 1
