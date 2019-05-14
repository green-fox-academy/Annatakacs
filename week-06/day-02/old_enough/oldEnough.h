//
// Created by Takacs Anna on 2019-05-14.
//

#ifndef OLD_ENOUGH_OLDENOUGH_H
#define OLD_ENOUGH_OLDENOUGH_H
#define DRINKING_AGE 18

#include <stdio.h>
#include <stdlib.h>

int askForAge()
{
    int age;
    printf("How old are you?\n");
    scanf("%d", &age);
    return age;
}

void isOldEnough(int age)
{
    if (age < DRINKING_AGE) {
        printf("You are not old enough to drink yet");
    } else {
        printf("Feel free to drink as much as you want to");
    }
}

#endif //OLD_ENOUGH_OLDENOUGH_H
