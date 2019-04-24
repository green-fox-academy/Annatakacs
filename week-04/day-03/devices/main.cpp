#include <iostream>
#include <vector>
#include "printer.h"
#include "printer2d.h"
#include "printer3d.h"
#include "copier.h"
#include "scanner.h"

int main()
{
    // Create a vector that holds Printer* objects
    // Fill the vector with 3 Printer2D, 2 Printer3D and 1 copier.
    // Iterate through the vector and invoke print function on all of them.

    // Create a vector that holds Scanner* objects
    // Fill the vector with 2 Scanner and 2 Copier objects.
    // Iterate through the vector and invoke scan function on all of them

    // Create a Copier object and invoke copy function on it.

    Printer2d sony(2, 4);
    Printer2d canon(5, 10);
    Printer2d ericsson(10, 20);

    Printer3d cool(2, 4, 6);
    Printer3d stuff(3, 6, 9);

    Copier nikon(5, 10, 15);

    std::vector<Printer *> printers;

    printers.push_back(&sony);
    printers.push_back(&canon);
    printers.push_back(&ericsson);
    printers.push_back(&cool);
    printers.push_back(&stuff);
    printers.push_back(&nikon);

    for(unsigned int i = 0; i < printers.size(); i++) {
        printers[i]->print();
    }

    Scanner samsung(23);
    Scanner lg(45);

    Copier apple(23, 25, 34);
    Copier windows(20, 22, 45);

    std::vector<Scanner *> scanners;

    scanners.push_back(&samsung);
    scanners.push_back(&lg);
    scanners.push_back(&apple);
    scanners.push_back(&windows);

    for(unsigned int i = 0; i < scanners.size(); i++) {
        scanners[i]->scan();
    }

    windows.copy();

    return 0;
}