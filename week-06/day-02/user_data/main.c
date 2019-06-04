#include <stdio.h>
#include <string.h>

// create a program which asks for full name and age
// and stores it in a char array
// parse that array to first_name, last_name, age (use tokenizing)
// print out the the stored variables
// example:
//   printf("Your name is: %s %s and you are %d years old", first_name, last_name, age);

int main()
{
    char info_array[100];
    printf("Type in your full name and age divided by backspace.\n");
    gets(info_array);

    char *first_name;
    char *last_name;
    char *age;

    char *p = strtok(info_array, " ");
    last_name = p;
    p = strtok(NULL, " ");
    first_name = p;
    p = strtok(NULL, " ");
    age = p;

    printf("Your name is: %s %s and you are %d years old", first_name, last_name, atoi(age));

    return 0;
}