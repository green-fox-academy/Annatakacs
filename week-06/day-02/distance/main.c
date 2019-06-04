#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// returns the distance between the first and last occurrence of character 's'

int gets_distance(char str[], int number);

int main ()
{
    char str[] = "This is a sample string";
    char *first, *last;

    int distance = gets_distance(str, 100);
    printf("%d", distance);

    return 0;
}

int gets_distance(char str[], int number)
{
    char *first_ptr = strchr(str, 's');
    char *last_ptr = strrchr(str, 's');

    int distance = 0;

    while(first_ptr != last_ptr) {
        distance++;
        first_ptr++;
    }
    return distance;
}