#include <stdio.h>
#include <stdlib.h>
#include "oldEnough.h"

int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary

    int age = askForAge();
    isOldEnough(age);

    return 0;
}