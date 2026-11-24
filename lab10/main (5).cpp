#include <iostream>

int main() {
    double d[1000 / sizeof(double) + 1];
    int i[1000 / sizeof(int) + 1];
    char c[1000 / sizeof(char) + 1];

    std::cout << "double: " << &d[1000 / sizeof(double)] - &d[0] << std::endl;
    std::cout << "int: " << &i[1000 / sizeof(int)] - &i[0] << std::endl;
    std::cout << "char: " << &c[1000 / sizeof(char)] - &c[0] << std::endl;
}
