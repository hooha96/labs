#include <stdio.h>
#include <cs50.h>
#include <math.h>

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
    return 1;
}

int main(void){
    
    long num = get_long("Please enter your credit card number:\n");
    int l = floor(log10(num)) + 1;
    int d = digit_check(num, l);

    //Checks if AMEX Card
    if (l == 15 && (d == 34 || d == 37)){
        if (luhn(num, l, d)){
            printf("AMEX\n");
        }
        else
            printf("INVALID\n");
    }

    //Checks if MASTER Card
    if (l == 16 && (d == 51 || d == 52 || d == 53 || d == 54 || d == 55)){
        if (luhn(num, l, d)){
            printf("MASTERCARD\n");
        }
        else
            printf("INVALID\n");
    }

    //Checks if VISA Card
    if ((l == 13 || l == 16) && (floor(d / 10) == 4)){
        if (luhn(num, l, d)){
            printf("VISA\n");
        }
        else
            printf("INVALID\n");
    }

    else{
        printf("INVALID\n");
    }

    return 1;
}
