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
  Rational() : Rational(1, 0, 1){};
  std::string string() const;
  auto operator+(Rational const &) const -> Rational;
  auto operator-() const -> Rational { return {-num, den}; };
  auto operator-(Rational const &) const -> Rational;
  auto operator*(Rational const &) const -> Rational;
  auto operator/(Rational const &) const -> Rational;
  auto operator*=(Rational const &) -> Rational;
  // Rational &operator-=(Rational);
  auto operator==(Rational const &) const -> bool;
  auto operator<(Rational const &) const -> bool;
  auto operator>(Rational const &) const -> bool;
  auto operator!=(Rational const &r) const -> bool { return !(*this == r);};
  auto operator<=(Rational const &r) const -> bool { return !(*this > r); };
  auto operator>=(Rational const &r) const -> bool { return !(*this < r); };
};

inline auto Rational::operator*=(Rational const &r) -> Rational { 
  num *= r.num;
  den *= r.den;
  gcd = std::gcd(num, den);
  num /= gcd;
  den /= gcd;
  return *this;
}

inline Rational::Rational(int n, int d) {
  if (d == 0) throw std::runtime_error("division by zero");
  gcd = std::gcd(n, d);
  num = n / gcd;
  den = d / gcd;
}

inline auto Rational::string() const -> std::string {
  return "num = " + std::to_string(num) + ", den = " + std::to_string(den) +
         ", gcd = " + std::to_string(gcd);
}

inline std::ostream &operator<<(std::ostream &os, Rational const &r) {
  return os << r.num << "//" << r.den;
}

inline auto Rational::operator+(Rational const &r) const -> Rational {
  auto m = den * r.den;
  auto n1 = num * r.den;
  auto n2 = r.num * den;
  return Rational(n1 + n2, m);
}

inline auto Rational::operator-(Rational const &r) const -> Rational { return *this + -r; }

inline auto Rational::operator*(Rational const &r) const -> Rational {
  return Rational(num * r.num, den * r.den);
}

inline auto Rational::operator/(Rational const &r) const -> Rational {
  return Rational(num * r.den, den * r.num);
}

inline auto Rational::operator==( Rational const &r) const -> bool {
  return (num == r.num) && (den == r.den);
}

inline auto Rational::operator<(Rational const &r) const -> bool {
  auto n = *this - r;
  return n.num < 0;
}

inline auto Rational::operator>(Rational const &r) const -> bool {
  auto n = *this - r;
  return n.num > 0;
}