#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter,
// and splits a string to words by space
// solve the problem with the proper string.h function

void sentence_to_words(char string[], int number);

int main()
{
    printf("Type in a sentence:\n\n");
    char string[256] = "This is a long, long and also very long sentence.";

    sentence_to_words(string, 256);
    
    return(0);
}

void sentence_to_words(char string[], int number)
{
    char *token;
    token = strtok(string, " ");

    while (token != NULL) {
        printf("%s\n", token);
        //puts(token);
        token = strtok(NULL, " ");
    }
}