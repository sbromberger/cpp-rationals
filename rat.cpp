#include "rat.hpp"

int main() {
  auto r1 = Rational(2, 3);
  auto r2 = Rational(10, 20);
  auto r3 = r1 + r2;
  auto r4 = -r1;
  auto r5 = r1 - r2;
  auto r6 = Rational(2);
  std::cout << "r1 " << r1 << ": " << r1.string() << std::endl;
  std::cout << "r2 " << r2 << ": " << r2.string() << std::endl;
  std::cout << "r3 " << r3 << ": " << r3.string() << std::endl;
  std::cout << "r4 " << r4 << ": " << r4.string() << std::endl;
  std::cout << "r5 " << r5 << ": " << r5.string() << std::endl;
  std::cout << "r6 " << r6 << ": " << r6.string() << std::endl;
  std::cout << (r6 * r2) << ": " << (r6 * r2).string() << std::endl;
  std::cout << (r6 / r2) << ": " << (r6 / r2).string() << std::endl;
  std::cout << "Rational equals" << std::endl;
  std::cout << (r1 == Rational(8, 12)) << std::endl;
  std::cout << (Rational(2, 3).string()) << " and " << (Rational(4, 6).string())
            << std::endl;
  std::cout << "Rational lt" << std::endl;
  std::cout << (Rational(2, 3) < Rational(6, 7)) << std::endl;
  std::cout << (Rational(2, 3) < Rational(1, 7)) << std::endl;
  std::cout << "Rational *=" << std::endl;
  std::cout << r1 << " * " << r2 << " = " << r1 * r2 << std::endl;
  auto r7 = r2;
  r7 = r1;
  r1 *= r2;
  std::cout << "r1 now = " << r1 << std::endl;
  std::cout << "r7 now = " << r7 << std::endl;
  std::cout << "r6  = " << r6 << std::endl;
  std::cout << "r2  = " << r2 << std::endl;
  r6 /= r2;
  std::cout << "r6 now = " << r6 << std::endl;
  return (0);
}
