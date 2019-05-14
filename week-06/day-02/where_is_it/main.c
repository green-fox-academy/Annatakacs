#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findCharacter(char *string, char *x);

int main()
{
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //

    char string[100];
    char x[10];
    printf("What is your string?\n");
    scanf("%s", string);
    printf("Which letter should we find?\n");
    scanf("%s", x);

    int result = findCharacter(string, x);
    printf("%d", result);

    return 0;
}

int findCharacter(char *string, char *x)
{
    int counter = 0;
    char *result = strchr(string, *x);
    if (result == NULL) {
        return -1;
    } else {
        while (string != NULL) {
            if (result == string) {
                return counter;
            }
            counter++;
            string++;
        }
    }
}