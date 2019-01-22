#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int *p_a = &a;
    int b = 17;
    int *p_b = &b;

    int sum = *p_a + *p_b;

    std::cout << sum << std::endl;

    return 0;
}