#include <iostream>
#include <numeric>
#include <string>

class Rational {
  int gcd, num, den;

  friend std::ostream &operator<<(std::ostream &os, Rational const &r);

 public:
  Rational(int n, int d, int g) : gcd{g}, num{n}, den{d} {};
  Rational(int, int);
  Rational(int n) : Rational(1, n, 1){};
  std::string string() const;
  Rational operator+(Rational) const;
  Rational operator-() const { return {-num, den}; };
  Rational operator-(Rational) const;
  Rational operator*(Rational) const;
  Rational operator/(Rational) const;
  bool operator==(Rational) const;
  bool operator<(Rational) const;
  bool operator>(Rational) const;
  bool operator!=(Rational r) const { return !(*this == r); };
  bool operator<=(Rational r) const { return !(*this > r); };
  bool operator>=(Rational r) const { return !(*this < r); };
};

inline Rational::Rational(int n, int d) {
  if (d == 0) throw std::runtime_error("division by zero");
  gcd = std::gcd(n, d);
  num = n / gcd;
  den = d / gcd;
}

inline std::string Rational::string() const {
  return "num = " + std::to_string(num) + ", den = " + std::to_string(den) +
         ", gcd = " + std::to_string(gcd);
}

inline std::ostream &operator<<(std::ostream &os, Rational const &r) {
  return os << r.num << "//" << r.den;
}

inline Rational Rational::operator+(Rational r) const {
  auto m = den * r.den;
  auto n1 = num * r.den;
  auto n2 = r.num * den;
  return Rational(n1 + n2, m);
}

inline Rational Rational::operator-(Rational r) const { return *this + -r; }

inline Rational Rational::operator*(Rational r) const {
  return Rational(num * r.num, den * r.den);
}

inline Rational Rational::operator/(Rational r) const {
  return Rational(num * r.den, den * r.num);
}

inline bool Rational::operator==(Rational r) const {
  return (num == r.num) && (den == r.den);
}

inline bool Rational::operator<(Rational r) const {
  auto n = *this - r;
  return n.num < 0;
}

inline bool Rational::operator>(Rational r) const {
  auto n = *this - r;
  return n.num > 0;
}