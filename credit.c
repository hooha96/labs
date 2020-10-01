#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>

int digit_check(long num, int l);
bool luhn(long num, int l, int d);

int main(int argc, string argv[]){
    char *eptr;
    long num = strtol(argv[1], &eptr, 10);
    int l = floor(log10(num)) + 1;
    int d = digit_check(num, l);

    //Checks if AMEX Card
    if (l == 15 && (d == 34 || d == 37)){
        if (luhn(num, l, d)){
            printf("AMEX\n");
            return 0;
        }
        else
            printf("INVALID\n");
    }

    //Checks if MASTER Card
    if (l == 16 && (d == 51 || d == 52 || d == 53 || d == 54 || d == 55)){
        if (luhn(num, l, d)){
            printf("MASTERCARD\n");
            return 0;
        }
        else
            printf("INVALID\n");
    }

    //Checks if VISA Card
    if ((l == 13 || l == 16) && (floor(d / 10) == 4)){
        if (luhn(num, l, d)){
            printf("VISA\n");
            return 0;
        }
        else
            printf("INVALID\n");
    }

    else{
        printf("INVALID\n");
    }

    return 0;
}

int digit_check(long num, int l){
    int d;
    long digit = num;
    for (int i = 0; i < l-2; i++){
        digit = floor(digit / 10);
    }
    d = (int)digit;
    return d;
}

bool luhn(long num, int l, int d){
    long n = num;
    int sum = 0;
    int sum_digits = 0;
    int sum_total;
    int digits[l], temp[l];
    //prints credit card number to array digits[]
    for (int i = l-1; i >= 0; i--)
    {
        digits[i] = n % 10;
        n = n / 10;
    }
    //copies contents of digits to temp
    for (int z = 0; z < l; z++){
        temp[z] = digits[z];
    }
    //multiplies every other number starting second right by 2 and stores in temp
    for (int x = l-2; x >= 0; x = x-2){
        temp[x] = digits[x] * 2;
    }
    //replaces other numbers with 0
    for (int x = l-1; x >= 0; x = x-2){
        temp[x] = 0;
    }
    //calculates sum of product digits
    for (int q = 0; q < l; q++){
        if (temp[q] > 9){
            sum = sum + (floor(temp[q] / 10) + (temp[q] % 10));
        }
        else
            sum += temp[q];
    }
    //prints sum of all other digits not multiplied by 2
    for (int i = l-1; i >= 0; i = i - 2){
        sum_digits += digits[i];
    }
    /*//for test purposes: prints array digits after manipulation
    for (int j = 0; j < l; j++){
        printf("%i ", digits[j]);
    }
    printf("\n");
    for (int y = 0; y < l; y++){
        printf("%i ", temp[y]);
    }*/

    sum_total = sum + sum_digits;

    if (sum_total % 10 == 0){
        return 1;
    }
    else
        return 0;
}