#ifndef POINTS_POINT_H
#define POINTS_POINT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
    float x;
    float y;
};

void create_point(float x, float y)
{
    struct point point1;
    point1.x = x;
    point1.y = y;
}

double calculate_distance(struct point point1, struct point point2)
{
    float distance;
    float xdiff = fabs(point2.x) - fabs(point1.x);
    float ydiff = fabs(point2.y) - fabs(point1.y);

    distance = sqrtf((xdiff * xdiff) + (ydiff * ydiff));

    return distance;

}

#endif //POINTS_POINT_H
