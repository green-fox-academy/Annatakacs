#ifndef SANDWICH_SANDWICH_H
#define SANDWICH_SANDWICH_H

#include <stdio.h>

typedef struct {
    char name[30];
    float price;
    float weight;
} sandwich_t;

float calculate_price(sandwich_t sandwich, int number)
{
    float price = sandwich.price * number;
    return price;
}

#endif //SANDWICH_SANDWICH_H
