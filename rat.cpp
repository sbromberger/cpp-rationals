#include "rat.hpp"

int main() {
    auto r1 = Rational(2, 3);
    auto r2 = Rational(10, 20);
    auto r3 = r1 + r2;
    auto r4 = -r1;
    auto r5 = r1 - r2;
    auto r6 = Rational(2);
    std::cout << r1 << ": " << r1.string() << std::endl;
    std::cout << r2 << ": " << r2.string() << std::endl;
    std::cout << r3 << ": " << r3.string() << std::endl;
    std::cout << r4 << ": " << r4.string() << std::endl;
    std::cout << r5 << ": " << r5.string() << std::endl;
    std::cout << (r6 * r2) << ": " << (r6 * r2).string() << std::endl;
    std::cout << (r6 / r2) << ": " << (r6 / r2).string() << std::endl;
    return (0);
}
