#include <iostream>
#include <cstdint>

int main() {
    double x[10];
    for (int i = 0; i < 10; i++)
        std::cout << &x[i] << ' '
                  << reinterpret_cast<std::uintptr_t>(&x[i]) << std::endl;
}
