#include <iostream>

int main() {
    int a[10];
    double b[10];
    char c[10];

    std::cout << &a[8] - &a[3] << std::endl;
    std::cout << &b[8] - &b[3] << std::endl;
    std::cout << &c[8] - &c[3] << std::endl;
}
