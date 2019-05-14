#include <stdio.h>
#include <stdlib.h>

int evenOrOdd(int input);

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)

    int input;
    printf("Please give me a number!\n");
    scanf("%d", &input);

    int result = evenOrOdd(input);
    printf("%d", result);

    return 0;
}

int evenOrOdd(int input)
{
    if (input % 2 == 0)
        return 1;
    else
        return 0;
}