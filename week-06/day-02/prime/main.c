#include <stdio.h>
#include <stdlib.h>

int isNumberPrime(int *number);

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)

    int number;
    printf("Please give me a number:\n");
    scanf("%d", &number);

    int result = isNumberPrime(&number);
    printf("%d", result);

    return 0;
}

int isNumberPrime(int *number)
{
    if (*number == 1) {
        return 0;
    } else if (*number == 2) {
        return 1;
    }
    int counter = 2;
    while (counter != *number) {
        if (*number % counter == 0) {
            return 0;
        }
        counter++;
    }
    return 1;
}