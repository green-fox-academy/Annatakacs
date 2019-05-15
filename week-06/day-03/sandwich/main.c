#include <stdio.h>
#include <string.h>
#include "sandwich.h"

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/

int main()
{
    sandwich_t pbj;
    strcpy(pbj.name, "PBJ");
    pbj.price = 5.75;
    pbj.weight = 55.634;

    int number = 18;

    printf("The price is: %f dollars", calculate_price(pbj, number));

    return 0;
}
