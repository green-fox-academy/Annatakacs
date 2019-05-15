#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main()
{
    FILE *fileptr;
    fileptr = fopen("../my-file.txt", "w");

    fputs("A long time ago in a galaxy far,", fileptr);
    fputs("far away....", fileptr);
    fputs("I have forgotten what I wanted to say ", fileptr);
    fputs("Awkward", fileptr);

    fclose(fileptr);

    FILE *fileptr2;
    //fileptr = NULL;
    fileptr2 = fopen("../my-file.txt", "r");
    char string[45];

    if (fileptr2 == NULL) {
        puts("Error loading file");
    } else {
        while (fgets(string, 45, fileptr2) != NULL) {
            puts(string);
        }
    }

    fclose(fileptr2);

    return 0;
}