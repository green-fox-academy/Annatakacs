#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free


int main()
{
    int *pointer = NULL;
    int size = 10;
    pointer = (int *) malloc(size * sizeof(int));

    if (!(int *) malloc(size * sizeof(int))) {
        printf("%s\n", "Error occurred while allocating memory.");
    } else {
        for (int i = 0; i < size; ++i) {
            pointer[i] = 2 * i;
        }
    }

    for (int j = 0; j < size; ++j) {
        printf("%d\n", pointer[j]);
    }

    pointer = realloc(pointer, 0);
    pointer = NULL;


    return 0;
}