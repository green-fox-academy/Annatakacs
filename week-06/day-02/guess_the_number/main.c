#include <stdio.h>

int main()
{
    // Write a program that stores a number, and the user has to figure it out.
// The user can input guesses, after each guess the program would tell one
// of the following:
//
// The stored number is higher
// The stored number is lower
// You found the number: 8

    int number = 8;
    int input;

    printf("Try to guess the number! \n");
    scanf("%d", &input);

    while (input != number) {
        if (input < number) {
            printf("The stored number is higher \n");
            printf("Try to guess the number! \n");
            scanf("%d", &input);
        } else {
            printf("The stored number is lower\n");
            printf("Try to guess the number! \n");
            scanf("%d", &input);
        }
    }

    if (input == number) {
        printf("You found the number %d \n", number);
    }

    return 0;
}