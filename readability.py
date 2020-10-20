from cs50 import get_string
import math

def main():
    l = 0
    s = 0

    text = get_string("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # print(f"There were {letters} letters in this text.")
    # print(f"There were {words} words in this text.")
    # print(f"There were {sentences} sentences in this text")

    l = float(letters * 100) / float(words)
    s = float(sentences * 100) / float(words)

    index = round(0.0588 * l - 0.296 * s - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")

def count_sentences(text):
    count = 0

    for i in range(len(text)):
        if text[i] == '.' or text[i] == '!' or text[i] == '?':
            count += 1
        else:
            continue

    return count

def count_words(text):
    count = 0

    for j in range(len(text)):
        if text[j] == ' ':
            count += 1
        else:
            continue

    return count + 1

def count_letters(text):
    count = 0

    for k in range(len(text)):
        if (text[k] >= 'a' and text[k] <= 'z') or (text[k] >= 'A' and text[k] <= 'Z'):
            count += 1
        else:
            continue

    return count

main()