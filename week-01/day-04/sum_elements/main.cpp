
#include <iostream>
#include <string>

//int sum(int[]);
void sum(int[]);

int main(int argc, char* args[]) {

    // - Create an array variable named `r`
    //   with the following content: `[54, 23, 66, 12]`
    // - Print the sum of the second and the third element

    int r[] = {54, 23, 66, 12};

    //std::cout << sum(r) << std::endl;

    sum(r);
    
    return 0;
}
//int sum(int x[]) {
   // return x[1] + x[2];
//}
void sum(int x[]) {
    std::cout << x[1] + x[2] << std::endl;
}