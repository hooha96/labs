#include <stdio.h>
#include <cs50.h>
#include <math.h>

int count_letters(string txt);
int count_words(string txt);
int count_sentences(string txt);

int main (void) {

    float index;
    float l = 0;
    float s = 0;
    string text = get_string("Text: ");
    //string text = "Congratulations! Today is your day. You're off to Great Places! You're off and away!";
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    printf("There were %i letters in this text.\n", letters);
    printf("There were %i words in this text.\n", words);
    printf("There were %i sentences in this text.\n", sentences);

    l = (float) letters * 100 / (float) words;
    s = (float) sentences * 100 / (float) words;

    index = round(0.0588 * l - 0.296 * s - 15.8);
    if(index < 1)
        printf("Before Grade 1\n");
    else if (index >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %1.0f\n", index);
}

int count_sentences(string txt){
    int i = 0;
    int count = 0;

    while (txt[i] != '\0'){
        if (txt[i] == '.' || txt[i] == '!' || txt[i] == '?'){
            count++;
            i++;
        }
        else{
            i++;
        }
    }

    return count;
}

int count_words(string txt){
    int i = 0;
    int count = 0;

    while (txt[i] != '\0'){
        if(txt[i] == ' '){
            count++;
            i++;
        }
        else{
            i++;
        }
    }

    return count+1;
}

int count_letters(string txt){
    int i = 0;
    int count = 0;

    while (txt[i] != '\0'){
        if ((txt[i] >= 'a' && txt[i] <= 'z') || (txt[i] >= 'A' && txt[i] <= 'Z')){
            count++;
            i++;
        }
        else{
            i++;
        }
    }

    return count;
}