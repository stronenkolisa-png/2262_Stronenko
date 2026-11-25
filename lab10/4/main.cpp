#include <iostream>

int main() {
    unsigned a = 8, b = 3, c = 17;
    std::cout << a << ' ' << b << ' ' << c << " - -" << std::endl;

    unsigned *p = &a;
    std::cout << a << ' ' << b << ' ' << c << ' ' << *p << " -" << std::endl;

    unsigned *q = &b;
    std::cout << a << ' ' << b << ' ' << c << ' ' << *p << ' ' << *q << std::endl;

    *p += *q + c;
    std::cout << a << ' ' << b << ' ' << c << ' ' << *p << ' ' << *q << std::endl;
    c = *q;
    std::cout << a << ' ' << b << ' ' << c << ' ' << *p << ' ' << *q << std::endl;
    p = &c;
    std::cout << a << ' ' << b << ' ' << c << ' ' << *p << ' ' << *q << std::endl;
    c += a;
    std::cout << a << ' ' << b << ' ' << c << ' ' << *p << ' ' << *q << std::endl;
    *p += 10;
    std::cout << a << ' ' << b << ' ' << c << ' ' << *p << ' ' << *q << std::endl;
    *q = *p;
    std::cout << a << ' ' << b << ' ' << c << ' ' << *p << ' ' << *q << std::endl;
    q = p;
    std::cout << a << ' ' << b << ' ' << c << ' ' << *p << ' ' << *q << std::endl;
    *q += 10;
    std::cout << a << ' ' << b << ' ' << c << ' ' << *p << ' ' << *q << std::endl;
}
