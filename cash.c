#include <stdio.h>
#include <cs50.h>
#include <math.h>

void print_change(float change){

    float cents; 
    float c = change;
    int coins = 0;

    cents = c * 100;

    while (cents != 0){
        while (cents >= 25){
            coins = coins + 1;
            cents = cents - 25;
            break;
        }

        while (cents < 25 && cents >= 10){
            coins = coins + 1;
            cents = cents - 10;
            break;
        }

        while (cents < 10 && cents >= 5){
            coins = coins + 1;
            cents = cents - 5;
            break;
        }

        while (cents < 5 & cents >= 1){
            coins = coins + 1;
            cents = cents - 1;
            break;
        }

        if (cents < 1) {
            coins = coins / 1;
            cents = 0;
            break;
        }

        else{
            coins = coins / 1;
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
