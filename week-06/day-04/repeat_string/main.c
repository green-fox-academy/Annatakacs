#include <stdio.h>
#include <stdlib.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

char *repeat_string(char *string, int number);

int main()
{
    char *string = "Apple";
    int number = 15;

    char *result = repeat_string(string, number);
    printf("%s", result);

    return 0;
}

char *repeat_string(char *string, int number)
{
    int size = 0;
    for (int i = 0; string[i] != '\0'; ++i) {
        size++;
    }

    char *pointer = (char *) malloc((size * number) * sizeof(char));

    int counter = 0;
    while (counter != number) {
        int j = 0;
        while (j != (counter * size)) {
            j++;
        }
        for (int i = 0; string[i] != '\0'; ++i, ++j) {
            pointer[j] = string[i];
        }
        counter++;
    }
    return pointer;
}