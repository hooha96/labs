import csv
import cs50
from sys import argv, exit

def main():
    db = cs50.SQL("sqlite:///students.db")

    if len(argv) != 2:
            print("Incorrect number of command-line arguments. Exiting Program.")
            exit(1)

    first = []
    middle = []
    last = []
    house = []
    birth = []

    with open(argv[1], 'r') as csvFile:
        reader = csv.DictReader(csvFile)
        for row in reader:
            if count_names(row["name"]) == 2:
                first.append(row["name"].split(' ')[0])
                middle.append("NULL")
                last.append(row["name"].split(' ')[1])
            elif count_names(row["name"]) == 3:
                first.append(row["name"].split(' ')[0])
                middle.append(row["name"].split(' ')[1])
                last.append(row["name"].split(' ')[2])
            house.append(row["house"])
            birth.append(int(row["birth"]))

    # For testing purposes only - prints student first, (middle), last names, house, and birth year, can remove entirely.
    """
    for i in range(len(first)):
        if middle[i] != "NULL":
            print(f"{i+1} > {first[i]} {middle[i]} {last[i]} is from house {house[i]} born in {birth[i]}.")
        else:
            print(f"{i+1} > {first[i]} {last[i]} is from house {house[i]} born in {birth[i]}.")
    """

    # Inserts elements from arrays into appropriate fields in students.db
    for i in range(len(first)):
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first[i], middle[i], last[i], house[i], birth[i])

# Returns number of names for a given student. Returns 3 if student has a middle name otherwise returns 2.
def count_names(name):
    count = 1 # at least one given name
    for c in name:
        if c == " ":
            count += 1
    return count

main()