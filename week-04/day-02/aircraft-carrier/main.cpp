#include <iostream>
#include "aircraft.h"
#include "f16.h"
#include "f35.h"
#include "carrier.h"

int main()
{
    F16 airplane1;
    F16 airplane2;
    F16 airplane3;
    F35 airplane4;
    F35 airplane5;
    F35 airplane6;

    Carrier carrier(200, 500, 100);
    Carrier enemy(200, 1000, 1000);

    carrier.add(&airplane1);
    carrier.add(&airplane2);
    carrier.add(&airplane3);
    carrier.add(&airplane4);
    carrier.add(&airplane5);
    carrier.add(&airplane6);

    std::cout << carrier.getStatus() << std::endl;
    carrier.fill();
    std::cout << carrier.getStatus() << std::endl;

    carrier.fight(&enemy);
    std::cout << enemy.getStatus() << std::endl;
    std::cout << carrier.getStatus() << std::endl;

    carrier.fill();
    std::cout << carrier.getStatus() << std::endl;

    return 0;
}