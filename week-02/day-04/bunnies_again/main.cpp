#include <iostream>

//We have bunnies standing in a line, numbered 1, 2, ... The odd bunnies (1, 3, ..) have the normal 2 ears.
// The even bunnies (2, 4, ..) we'll say have 3 ears, because they each have a raised foot.
// Recursively return the number of "ears" in the bunny line 1, 2, ... n (without loops or multiplication).

int earcounter(int bunny, int);

int main() {

    int bunny;
    std::cout << "How many bunnies do we have?" << std::endl;
    std::cin >> bunny;

    if (bunny % 2 == 0) {
        std::cout << "The bunnies have " << earcounter(bunny, 3) << " ears";
    } else {
        std::cout << "The bunnies have " << earcounter(bunny, 2) << " ears";
    }

    return 0;
}

int earcounter(int bunny, int x) {
    if (bunny < 1)
        return 0;
    return x + earcounter((bunny-1), x);
}
