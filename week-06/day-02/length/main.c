#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfString(char name[100]);

int main()
{
    // Create a program which asks for the name of the user and stores it
    // Create a function which takes a string as a parameter and returns the length of it
    // Solve this exercise with and without using string.h functions

    char name[100];
    printf("What is your name?\n");
    scanf("%s", name);

    int size = lengthOfString(name);
    printf("%d\n", size);

    int length = strlen(name);
    printf("%d", length);

    return 0;
}

int lengthOfString(char name[100])
{
    int counter = 0;
    while (*(name++) != NULL) {
        counter++;
    }

    return counter;
}