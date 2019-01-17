#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `p1`
    //   with the following content: `[1, 2, 3]`
    // - Create an array variable named `p2`
    //   with the following content: `[4, 5]`
    // - Print if `p2` has more elements than `p1`

    int p1[] = {1, 2, 3};
    int p2[] = {4, 5};

    int result1 = ((sizeof (p1)) / (sizeof (p1[0])));
    int result2 = ((sizeof (p2)) / (sizeof (p2[0])));

    if (result1 < result2) {
        std::cout << "p2 has more elements than p1" << std::endl;
    }
        else {
            std::cout << "p1 has more elements than p2" << std::endl;
    }
    return 0;
}
