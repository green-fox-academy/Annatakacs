#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    BIG,
    MEDIUM,
    SMALL
} screensize_t;

typedef struct {
    char name[256];
    int release_year;
    screensize_t screensize;
} smartphones_t;

int count_lines(char *filename);
void file_to_string(char *filename, smartphones_t phone_array[]);
smartphones_t line_to_struct(char *buffer);
char *get_oldest_phone(smartphones_t phone_array[], int size);
int get_screen_size_count(smartphones_t phone_array[], int size, screensize_t screensize);
int calcualte_price(smartphones_t smartphone);
void write_to_file(smartphones_t phone_array[], int size);

int main(void) {

    int lines = count_lines("../phones.txt");
    const smartphones_t phone_array[lines];
    file_to_string("../phones.txt", phone_array);
    char *oldest_phone = get_oldest_phone(phone_array, lines);
    int number_of_big = get_screen_size_count(phone_array, lines, BIG);
    printf("There are %d phones with big screen.\n", number_of_big);
    int number_of_small = get_screen_size_count(phone_array, lines, SMALL);
    printf("There are %d phones with big screen.\n", number_of_small);

    write_to_file(phone_array, lines);

    return 0;
}

int count_lines(char *filename)
{
    FILE *fptr;
    fptr = fopen(filename, "r");
    char buffer[100];
    int counter = 0;

    if (fptr == NULL) {
        printf("Error occurred while opening the file");
    }
    while (fgets(buffer, 100, fptr) != NULL) {
        counter++;
    }
    fclose(fptr);

    return counter;

}

void file_to_string(char *filename, smartphones_t phone_array[])
{
    FILE *fptr;
    fptr = fopen(filename, "r");
    char buffer[100];
    int size = 0;

    if (fptr == NULL) {
        printf("Error occurred while opening the file");
    }
    while (fgets(buffer, 100, fptr) != NULL) {
        phone_array[size] = line_to_struct(buffer);
        size++;
    }
    fclose(fptr);
}


smartphones_t line_to_struct(char *buffer)
{
    smartphones_t smartphone;
    char *token = strtok(buffer, " ");
    strcpy(smartphone.name, token);
    token = strtok(NULL, " ");
    smartphone.release_year = atoi(token);
    token = strtok(NULL, " ");

    int i = 0;
    while (token[i] != '\n') {
        i++;
    }
    token[i] = '\0';
    if (atoi(token) >= 15) {
        smartphone.screensize = BIG;
    } else if (atoi(token) >= 12) {
        smartphone.screensize = MEDIUM;
    } else {
        smartphone.screensize = SMALL;
    }

    return smartphone;
}

char *get_oldest_phone(smartphones_t phone_array[], int size)
{
    int year = 9999;
    static char name[20] = "";
    for (int i = 0; i < size; ++i) {
        if (phone_array[i].release_year < year) {
            year = phone_array[i].release_year;
            strcpy(name, phone_array[i].name);
        }
    }

    printf("The %s is the oldest device in the database.\n", name);
    return name;
}

int get_screen_size_count(smartphones_t phone_array[], int size, screensize_t screensize)
{
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (phone_array[i].screensize == screensize) {
            counter++;
        }
    }
    return counter;
}

void write_to_file(smartphones_t phone_array[], int size)
{
    FILE *fptr;
    fptr = fopen("../prices.txt", "w");

    for (int i = 0; i < size; ++i) {
        int price = calcualte_price(phone_array[i]);
        fprintf(fptr, "%s %d\n", phone_array[i].name, price);
    }
    fclose(fptr);
}

int calcualte_price(smartphones_t smartphone)
{
    int base = 300;
    if (smartphone.screensize == MEDIUM) {
        base += 100;
    } else if (smartphone.screensize == BIG) {
        base *= 2;
    }

    int years_passed = 2019 - smartphone.release_year;
    int lost_value = 0;
    int year = 0;
    while (year != years_passed) {
        if (lost_value <= 250) {
            lost_value += 50;
        }
        year++;
    }
    base -= lost_value;
    return base;
}