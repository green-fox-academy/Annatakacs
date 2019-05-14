#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *appendA(char string[50]);

int main()
{
    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string

    char string[50];
    printf("Please give me a string!\n");
    scanf("%s", string);

    char *result = appendA(string);
    printf("%s", result);

    return 0;
}

const char *appendA(char string[50])
{
    strcat(string, "a");
    return string;
}