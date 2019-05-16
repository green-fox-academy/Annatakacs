#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int* pointer = NULL;
    int number;
    printf("Please enter a number\n");
    scanf("%d", &number);

    pointer = (int *) calloc(number, sizeof(int));
    int sum = 0;
    printf("Please enter %d numbers:\n", number);
    int input;
    for (int i = 0; i < number; ++i) {
        scanf("%d", &input);
        pointer[i] = input;
        sum += input;
    }

    free(pointer);
    pointer = NULL;

    int *pointer2 = NULL;
    pointer2 = (int *) calloc(sum, sizeof(int));
    for (int j = 0; j <= sum; ++j) {
        pointer2[j] = j;
    }

    for (int j = 0; j <= sum; ++j) {
        printf("%d\n", pointer2[j]);
    }

    free(pointer2);
    pointer2 = NULL;

    return 0;
}