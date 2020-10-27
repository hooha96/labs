#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Asks user for name
    string name = get_string("What is your name?\n");

    // Prints user's name
    printf("hello, %s.\n", name);
}