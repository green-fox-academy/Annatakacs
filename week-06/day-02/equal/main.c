#include <stdio.h>
#include <stdlib.h>
#include "equal.h"

int main()
{
    // Create a program which asks for two integers and stores them separately
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise

    int number1;
    int number2;
    printf("Please give me your first number\n");
    scanf("%d", &number1);
    printf("Please give me your second number\n");
    scanf("%d", &number2);

    int result = isEqual(number1, number2);
    printf("%d", result);

    return 0;
}