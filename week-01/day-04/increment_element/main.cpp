#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `t`
    //    with the following content: `[1, 2, 3, 4, 5]`
    // - Increment the third element
    // - Print the third element

    int t[] = {1, 2, 3, 4, 5};

    t[3] += 10;

    std::cout << "The 3. element: " << t[3] << std::endl;

    return 0;
}