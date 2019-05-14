#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int checkIfStringsAreEqual(char string1[100], char string2[100]);

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char string1[100];
    char string2[100];

    puts("Feed me with a string, hooman!");
    gets(string1);
    puts("Feed me with a second string, hooman!");
    gets(string2);

    int result = checkIfStringsAreEqual(string1, string2);
    printf("%d", result);

    return 0;
}

int checkIfStringsAreEqual(char string1[100], char string2[100])
{
    for (int i = 0; i < 100; ++i) {
        string1[i] = tolower(string1[i]);
        string2[i] = tolower(string2[i]);

    }

    int result = strcmp(string1, string2);
    if (result != 0)
        return 0;
     else
        return 1;
}