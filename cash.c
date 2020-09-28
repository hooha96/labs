#include <stdio.h>
#include <cs50.h>
#include <math.h>

void print_change(float change){

    float cents, nickels, dimes, quarters; 
    float c = change;
    int coins = 0;

    cents = (c * 100);
    nickels = floor(cents / 5);
    dimes = floor(cents / 10);
    quarters = floor(cents / 25);

    while (cents > 0){
        if (cents >= 25){
            coins = coins + 1;
            cents = cents - 25;
        }

        if (cents < 25 && cents >= 10){
            coins = coins + 1;
            cents = cents - 10;
        }

        if (cents < 10 && cents >= 5){
            coins = coins + 1;
            cents = cents - 5;
        }

        if (cents < 5 & cents >= 1){
            coins = coins + 1;
            cents = cents - 1;
        }

        else {
            coins = coins / 1;
            break;
        }
    }

    //printf("You have %.2f cents, %.2f nickels, %.2f dimes, and %.2f quarters.", cents, nickels, dimes, quarters);

    printf("Number of coins used = %i\n", coins);

}

int main(void){

    float change = 0;

    do {
        change = get_float("Enter amount of change owed: ");
    }
    while(change < 0);

    print_change(change);
}
