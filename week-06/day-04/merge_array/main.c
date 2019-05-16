#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

void bubble_sort(int *array, int size);

void swap(int *i, int *j);

int main()
{
    int size = 10;
    int *pointer = NULL;
    pointer = (int *) malloc(size * sizeof(int));
    int *pointer2 = NULL;
    pointer2 = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        pointer[i] = (2 * i) + 1;
        pointer2[i] = (2 * i);
    }

    pointer = (int *) realloc(pointer, (2 * size) * sizeof(int));
    for (int j = 0; j < (2 * size); ++j) {
        pointer[size + j] = pointer2[j];
    }

    free(pointer2);
    pointer2 = NULL;

    bubble_sort(pointer, size);

    for (int k = ((2 * size) - 1); k >= 0; --k) {
        printf("%d\n", pointer[k]);
    }

    free(pointer);
    pointer = NULL;

    return 0;
}

void bubble_sort(int *array, int size)
{
    for (int i = 0; i < ((2 * size) - 1); ++i) {
        for (int k = 0; k < ((2 * size) - i - 1); ++k) {
            if (array[k] > array[k + 1]) {
                swap(&array[k], &array[k + 1]);
            }
        }
    }
}

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}