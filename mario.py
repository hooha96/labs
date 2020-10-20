from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break

j = height-1
for i in range(1, height+1, 1):
    print((j * " ") + (i * "#"))
    j -= 1

#print("")

