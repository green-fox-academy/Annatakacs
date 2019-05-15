#include <stdio.h>
#include <string.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {
    VOLVO, TOYOTA, LAND_ROVER, TESLA
};

struct car {
    enum car_type type;
    double km;
    double gas;
};

const char *get_type(enum car_type);

void print_statistics(struct car *car1);

int main()
{
    struct car volvo;
    struct car toyota;
    struct car landrover;
    struct car tesla;

    volvo.type = VOLVO;
    volvo.gas = 99.9;
    volvo.km = 555.555;

    toyota.type = TOYOTA;
    toyota.gas = 98.9;
    toyota.km = 558.555;

    landrover.type = LAND_ROVER;
    landrover.gas = 97.9;
    landrover.km = 557.555;

    tesla.type = TESLA;
    tesla.gas = 96.9;
    tesla.km = 556.555;

    print_statistics(&volvo);
    print_statistics(&toyota);
    print_statistics(&landrover);
    print_statistics(&tesla);

    return 0;
}

const char *get_type(enum car_type type)
{
    switch (type) {
        case VOLVO:
            return "VOLVO";
        case TOYOTA:
            return "TOYOTA";
        case LAND_ROVER:
            return "LAND ROVER";
        case TESLA:
            return "TESLA";
    }
}

void print_statistics(struct car *car1)
{
    if (car1->type == TESLA) {
        printf("%s:\n kilometers: %f\n", get_type(car1->type), car1->km);
    } else {
        printf("%s:\n kilometers: %f\n gas level: %f\n", get_type(car1->type), car1->km, car1->gas);
    }
}
