#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

bool uniqueCharacters(string str);
void ciph (char *txt, string key);
int getIndex(char c);

int main(int argc, string argv[]){
    if (argc != 2){
        printf("Incorrect number of parameters entered.\nExiting program.\n");
        return 1;
    }
    if (strlen(argv[1]) != 26){
        printf("Invalid length of string.\nExiting program.\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++){
        if ((argv[1][i] < 'a' && argv[1][i] > 'Z') || (argv[1][i] < 'A' && argv[1][i] > 0) || (argv[1][i] > 'z' && argv[1][i] < 127)){
            printf("Incorrect character(s) entered.\nExiting program.\n");
            return 1;
        }
    }
    if (!uniqueCharacters(argv[1])){
        printf("Duplicate characters entered.\nExiting program.\n");
        return 1;
    }

    string text = get_string("plaintext: ");
    ciph(text, argv[1]);
}

void ciph (char *txt, string key){
    int index[strlen(txt)];
    char temp[strlen(txt)];
    for (int i = 0; i < strlen(txt); i++){
        index[i] = getIndex(txt[i]);
    }
    for (int j = 0; j < strlen(txt); j++){
        if (txt[j] >= 65 && txt[j] <= 90)
            txt[j] = toupper(key[index[j]]);
        if (txt[j] >= 97 && txt[j] <= 122)
            txt[j] = tolower(key[index[j]]);
    }
    printf("ciphertext: ");
    for (int x = 0; x < strlen(txt); x++){
        printf("%c", txt[x]);
    }
    printf("\n");
}

int getIndex(char c){
    string alpha_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alpha_lower = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < strlen(alpha_upper); i++){
        if (c >= 65 && c <= 90){
            if(c == alpha_upper[i]){
                return i;
            }
        }
        if (c >= 97 && c <= 122){
            if(c == alpha_lower[i]){
                return i;
            }
        }
    }
    return -1;
}

bool uniqueCharacters(string str)
{

    // If at any time we encounter 2
    // same characters, return false
    for (int i = 0; i < strlen(str); i++) {
        for (int j = i + 1; j < strlen(str); j++) {
            if (str[i] == str[j]) {
                return false;
            }
        }
    }

    // If no duplicate characters encountered,
    // return true
    return true;
}