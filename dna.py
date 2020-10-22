from sys import argv, exit
import csv
import re

def main():

    names = []
    agatc = []
    aatg = []
    tatc = []

    # Checks for appropriate use of command line arguments.
    if len(argv) != 3:
        print("Incorrect number of command-line arguments. Exiting Program.")
        exit(1)

    #Opens csv file
    with open(argv[1], 'r') as csvFile:
        reader = csv.DictReader(csvFile)
        dict_list = []
        for row in reader:
            dict_list.append(row)

    for i in range(len(dict_list)):
        names.append(dict_list[i]["name"])
        agatc.append(dict_list[i]["AGATC"])
        aatg.append(dict_list[i]["AATG"])
        tatc.append(dict_list[i]["TATC"])

    for i in range(len(agatc)):
        agatc[i] = int(agatc[i])
    for i in range(len(aatg)):
        aatg[i] = int(aatg[i])
    for i in range(len(tatc)):
        tatc[i] = int(tatc[i])

    # Opens text file and writes dna to string "dna"
    with open(argv[2],'r') as dnaFile:
        dna = dnaFile.read()

    max_agatc = check_agatc(dna)
    max_aatg = check_aatg(dna)
    max_tatc = check_tatc(dna)

    ag = 0
    aa = 1
    ta = 2

    for i in range(len(agatc)):
        if max_agatc == agatc[i]:
            ag = i
            break
    for i in range(len(aatg)):
        if max_aatg == aatg[i]:
            aa = i
            break
    for i in range(len(tatc)):
        if max_tatc == tatc[i]:
            ta = i
            break

    if (ag == aa and aa == ta and ag == ta):
        print(names[ag])
    else:
        print("No match")

def check_agatc(dna):

    x = re.findall(r'AGATC', dna)

    return len(x)

def check_aatg(dna):

    y = re.findall(r'AATG', dna)

    return len(y)

def check_tatc(dna):

    z = re.findall(r'TATC', dna)

    return len(z)

main()
