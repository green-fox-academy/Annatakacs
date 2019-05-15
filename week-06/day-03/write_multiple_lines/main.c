#include <stdio.h>
#include <string.h>

void write_into_file(char[30], char[30], int);

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

int main()
{
    char path[30] = "../my-file.txt";
    char word[30] = "banana";
    int number = 15;

    write_into_file(path, word, number);

    return 0;
}

void write_into_file(char path[30], char word[30], int number)
{
    FILE *fileptr;
    fileptr = fopen(path, "w+");
    int counter = 0;

    if (fileptr == NULL) {
        perror("Error occurred while handling file");
    } else {
        while (counter != number) {
            fprintf(fileptr, "%s\n", word);
            counter++;
        }
    }
    fclose(fileptr);
}