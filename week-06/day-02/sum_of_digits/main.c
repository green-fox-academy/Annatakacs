#include <stdio.h>
#include <stdlib.h>

int isSumOfDigits(int *number);

int isSumEqual(int result1, int result2);

int main()
{
    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise
    //
    // For example:
    //
    // Case 1:
    //
    // a = 123
    // b = 321
    //
    // sum of number of digits (variable a) = 1 + 2 + 3 = 6
    // sum of number of digits (variable b) = 3 + 2 + 1 = 6
    // in this case the function should return 1
    //
    //
    // Case 2:
    //
    // a = 723
    // b = 114
    //
    // sum of number of digits (variable a) = 7 + 2 + 3 = 12
    // sum of number of digits (variable b) = 1 + 1 + 4 = 6
    // in this case the function should return 0


    char input1 = "";
    char input2 = "";
    int number1;
    int number2;
    printf("Please enter your first number:\n");
    scanf("%s", &input1);
    number1 = atoi(&input1);
    printf("Please enter your second number:\n");
    scanf("%s", &input2);
    number2 = atoi(&input2);

    int result1 = isSumOfDigits(&number1);
    int result2 = isSumOfDigits(&number2);

    int equalOrNot = isSumEqual(result1, result2);
    printf("%d", equalOrNot);

    return 0;
}

int isSumOfDigits(int *number)
{
    int sum;
    while (*(number++) != NULL) {
        sum += *number;
    }
}

int isSumEqual(int result1, int result2)
{
    if (result1 == result2) {
        return 1;
    } else
        return 0;
}