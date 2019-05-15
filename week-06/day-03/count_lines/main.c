#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file

int number_of_lines(char string[30]);

int main ()
{
    int result = number_of_lines("../myfile.txt");
    printf("The amount of lines: %d", result);

    return 0;
}

int number_of_lines(char string[30])
{
    FILE *fileptr;
    fileptr = fopen(string, "r");
    int counter = 0;
    char line[500];

    if (fileptr == NULL) {
        perror("Error handling file");
        return 0;
    } else {
        while (fgets(line, 500, fileptr) != NULL) {
            counter++;
        }
    }
    return counter;
}
