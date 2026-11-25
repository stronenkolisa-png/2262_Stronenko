#include <iostream>

int main() {
    double x[9] = {};
    int y[9] = {};
    char z[9] = {};
    double *d = &x[4];
    int *i = &y[4];
    char *c = &z[4];

    std::cout << "double: " << ((d + 4) - (d - 4)) * sizeof(*d) << std::endl;
    std::cout << "int: " << ((i + 4) - (i - 4)) * sizeof(*i) << std::endl;
    std::cout << "char: " << ((c + 4) - (c - 4)) * sizeof(*c) << std::endl;
}
