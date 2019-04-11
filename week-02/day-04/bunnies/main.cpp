#include <iostream>

//We have a number of bunnies and each bunny has two big floppy ears.
// We want to compute the total number of ears across all the bunnies recursively (without loops or multiplication).

int earcounter(int ears, int bunny);

int main() {

    int ears = 2;
    int bunny;
    std::cout << "How many bunnies do we have?" << std::endl;
    std::cin >> bunny;

    std::cout << "The " << bunny << " bunnies have " << earcounter(ears, bunny) << " ears." << std::endl;
    return 0;
}
int earcounter(int ears, int bunny) {
    if (bunny < 1)
        return 0;
    return ears + earcounter(ears, (bunny -1));
}