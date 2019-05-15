#include <stdio.h>
#include <string.h>
#include "house.h"

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

int main()
{
    house_t blue;
    house_t green;
    house_t yellow;
    house_t purple;

    blue.price = 200;
    strcpy(blue.address, "Budapest");
    blue.area = 90.9;
    blue.rooms = 3;

    green.price = 300;
    strcpy(green.address, "Vienna");
    green.area = 90.9;
    green.rooms = 3;

    yellow.price = 400;
    strcpy(yellow.address, "Prague");
    yellow.area = 90.9;
    yellow.rooms = 3;

    purple.price = 500;
    strcpy(purple.address, "NYC");
    purple.area = 90.9;
    purple.rooms = 3;

    house_t house_array[] = {blue, green, yellow, purple};
    int size = sizeof(house_array) / sizeof(house_array[0]);

    int result = count_worthy_houses(house_array, size);
    printf("The amount of houses that are worth it: %d", result);

  return 0;
}
