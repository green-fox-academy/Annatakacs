#include<stdio.h>

int main()
{
    // Create a program that prints a few operations on two numbers: 22 and 13

    int number1 = 22;
    int number2 = 13;

    // Print the result of 13 added to 22

    int sum = number1 + number2;
    printf("%d\n", sum);

    // Print the result of 13 substracted from 22

    int result1 = number1 - number2;
    printf("%d\n", result1);

    // Print the result of 22 multiplied by 13

    int result2 = number1 * number2;
    printf("%d\n", result2);

    // Print the result of 22 divided by 13 (as a decimal fraction)

    float result3 = (float)number1 / number2;
    printf("%f\n", result3);

    // Print the reminder of 22 divided by 13

    int result4 = number1 % number2;
    printf("%d\n", result4);

    // Store the results in variables and use them when you display the result

    return 0;
}