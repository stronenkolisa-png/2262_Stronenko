#include <iostream>

int main() {
    int a = 6, b = 3;
    int *p = &a;
    int &r = b;

    std::cout << *p << std::endl;
    std::cout << a * r << std::endl;
    std::cout << (a & r) << std::endl;
}
