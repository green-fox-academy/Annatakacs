#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// lists all position where character 'i' is found

void finds_positions_of_i(char string[], number);

int main()
{
    char string[55] = "This is a string for testing";

    finds_positions_of_i(string, 55);

    return 0;
}

void finds_positions_of_i(char string[], number)
{
    for (int i = 0; i < number; ++i) {
        if (string[i] == 'i') {
            printf("%d\n", i);
        }
    }
}