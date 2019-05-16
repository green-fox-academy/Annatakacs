#include <stdio.h>
#include <stdlib.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

char *concatenate_string(char *string, char *string2, int size, int size2);

int main()
{
    printf("Please enter a string:\n");
    int size = 1;
    char *string = (char *) calloc(size, sizeof(char));
    char c = getc(stdin);
    while (c != '\n') {
        size++;
        string = (char *) realloc(string, size * sizeof(char));
        string[size - 2] = c;
        string[size - 1] = '\0';
        c = getc(stdin);
    }

    printf("Please enter a second string:\n");
    int size2 = 1;
    char *string2 = (char *) calloc(size2, sizeof(char));
    char c2 = getc(stdin);
    while (c2 != '\n') {
        size2++;
        string2 = (char *) realloc(string2, size2 * sizeof(char));
        string2[size2 - 2] = c2;
        string2[size2 - 1] = '\0';
        c2 = getc(stdin);
    }

    char *result = concatenate_string(string, string2, size, size2);
    printf("%s", result);

    return 0;
}

char *concatenate_string(char *string, char *string2, int size, int size2)
{
    string = (char *) realloc(string, (size + size2) * sizeof(char));
    int i = 0;
    int j = 0;
    while (string[i] != '\0') {
        i++;
    }
    while (string2[j] != '\0') {
        string[i] = string2[j];
        i++;
        j++;
    }

    return string;
}