#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14

float areaOfCircle(int radius);
// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that circle
// area = radius * radius * PI

int main()
{
    srand(time(NULL));
    int radius = rand() % 20;
    double area = areaOfCircle(radius);
    printf("The area of a circle with a radius of %d is: %.3f\n", radius, area);

    return 0;
}

float areaOfCircle(int radius)
{
    double area = radius * radius * PI;
    return area;
}