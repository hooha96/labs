//Doesn't work exactly as specified
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;

    // Repeats loop until user input between 1 and 8 inclusive
    do{
        height = get_int("Please input pyramid height:\n");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++){

        // Prints spaces hwight-i-1 times
        for (int s = height - 1; s > i; s--){
            printf(" ");
        }

        // Print '#' (i + 1) times
        for (int h = -1; h < i; h++){
            printf("#");
        }

        // Moves to next line
        printf("\n");
    }

}
