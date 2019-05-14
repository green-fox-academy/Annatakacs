#include <stdio.h>

int main()
{
    // Write a program that stores 3 sides of a cuboid as variables (doubles)
// You should get these variables via console input
// The program should write the surface area and volume of the cuboid like:
//
// Surface Area: 600
// Volume: 1000

    int length;
    int width;
    int height;

    printf("What is the length of your cuboid?\n");
    scanf("%d", &length);
    printf("What is the width of your cuboid?\n");
    scanf("%d", &width);
    printf("What is the height of your cuboid?\n");
    scanf("%d", &height);

    int volume = length * width * height;
    printf("Volume: %d\n", volume);

    int area = 2 * (length * width + width * height + height * length);
    printf("Surface Area: %d\n", area);

    return 0;
}