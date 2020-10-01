#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

void ciph (char *txt, float k);

int main(int argc, char *argv[]){

    //Takes argument, converts to float and quits program if argument is negative, invalid number of args or non-decimal.
    char *a = argv[1];
    float num = atof(a);
    if (num < 0){
        printf("Please enter a positive value.\n");
        return 1;
    }
    if (fmod(num,1) != 0){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (argc != 2){
        printf("Incorrect parameter(s) entered.\n");
        return 1;
    }

    string text = get_string("plaintext: ");
    printf("String: %s\n", text);

    ciph(text, num);
    return 0;
    //printf("%.1f\n", num);
}

void ciph (char *txt, float k){
    int j = 0;
    while (txt[j] != '\0'){
        if ((txt[j] >= 'a' && txt[j] <= 'z') || (txt[j] >= 'A' && txt[j] <= 'Z')){
            txt[j] += k;
            if (txt[j] > 'Z' && txt[j] < 'a')
                txt[j] -= 26;
            if (txt[j] > 'z' && txt[j] <= 127)
                txt[j] -= 26;
            if (txt[j] < 0)
                txt[j] = '!';
            j++;
        }
        else{
            j++;
        }
    }
    printf("ciphertext: ");
    for (int i = 0; i < strlen(txt); i++){
        printf("%c", txt[i]);
    }
    printf("\n");
}

