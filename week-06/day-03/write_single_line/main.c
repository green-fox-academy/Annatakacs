#include <stdio.h>
#include <string.h>

void write_in_file(char file[30]);

// Open a file called "my-file.txt"
// Write your name in it as a single line

int main ()
{
    write_in_file("../my-file.txt");

    return 0;
}

void write_in_file(char file[30])
{
    FILE *fileptr;
    fileptr = fopen(file, "w");
    //fputs("Takacs Anna", fileptr);
    char name[30] = "Takács Anna";
    fprintf(fileptr, "%s", name);
    fclose(fileptr);
}