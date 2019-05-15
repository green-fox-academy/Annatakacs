#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"

/*
Create a point struct which has two float variables: x and y
Create a function that constructs a point
It should take it's x and y coordinate as parameter
Create a function that takes 2 points and returns the distance between them
Example:
int main()
{
	point_t p1 = create_point(1, 1);
	point_t p2 = create_point(1, 5.5);
	float dist = distance(p1, p2);
	printf("%f", dist);
	return 0;
}
*/

int main()
{
    struct point point1;
    struct point point2;
    point1 = create_point(0, 2.56);
    create_point(2.34, 4.56);

    double distance = calculate_distance(point1, point2);
    printf("The distance between the two points is: %f", distance);

    return 0;
}