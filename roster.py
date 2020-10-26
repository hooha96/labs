import csv
import cs50
from sys import argv, exit

def main():
    # opens/links database students.db
    db = cs50.SQL("sqlite:///students.db")

    # Checks if appropriate number of command line arguments are entered otherwise exits
    if len(argv) != 2:
            print("Incorrect number of command-line arguments. Exiting Program.")
            exit(1)

    # Queries for all field from students.db where house is command line argument and output sorted by last name alphabetically
    query = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first ASC", argv[1])

    # Prints to command line.
    for i in query:
        if i["middle"] != "NULL":
            print(f"{i['first']} {i['middle']} {i['last']}, born {i['birth']}")
        else:
            print(f"{i['first']} {i['last']}, born {i['birth']}")

main()