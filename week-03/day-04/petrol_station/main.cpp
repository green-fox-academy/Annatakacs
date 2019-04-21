#include <iostream>
#include "Station.h"
#include "Car.h"

int main()
{
    Station station (500);
    Car car1 (10, 8);
    Car car2 (15, 12);
    Car car3 (20, 18);
    Car car4 (25, 22);
    Car car5 (30, 25);

    station.fill(car1);
    station.fill(car2);
    station.fill(car3);
    station.fill(car4);
    station.fill(car5);


    std::cout << "Car1: " << car1.getgasAmount() << "/" << car1.getcapacity() << std::endl;
    std::cout << "Car2: " << car2.getgasAmount() << "/" << car2.getcapacity() << std::endl;
    std::cout << "Car3: " << car3.getgasAmount() << "/" << car3.getcapacity() << std::endl;
    std::cout << "Car4: " << car4.getgasAmount() << "/" << car4.getcapacity() << std::endl;
    std::cout << "Car5: " << car5.getgasAmount() << "/" << car5.getcapacity() << std::endl;

    std::cout << "Station: " << station.getgasAmount() << "/100 left" << std::endl;

    return 0;
}