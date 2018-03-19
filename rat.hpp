#include <iostream>
#include <numeric>
#include <string>

class Rational {
  int gcd, numerator, denominator;

  friend std::ostream &operator<<(std::ostream &os, Rational const &r);

 public:
  Rational(int, int);
  Rational(int n) : Rational(n, 1) {};
  Rational() : Rational(0, 1) {};
  // these consts are here because we want to specify that
  // we are not mutating any field.
  auto string() const -> std::string;
  // we use Rational const & here because it's better to pass
  // a reference than a copy of the object.
  auto operator+(Rational const &) const -> Rational;
  auto operator-() const -> Rational { return Rational(-numerator, denominator); };
  auto operator-(Rational const &) const -> Rational;
  auto operator*(Rational const &) const -> Rational;
  auto operator/(Rational const &) const -> Rational;
  // we don't use consts to mark the function here because
  // it mutates the operand.
  auto operator*=(Rational const &)->Rational;
  auto operator/=(Rational const &)->Rational;
  // Rational &operator-=(Rational);
  auto operator==(Rational const &) const->bool;
  auto operator<(Rational const &) const->bool;
  auto operator>(Rational const &) const->bool;
  auto operator!=(Rational const &r) const->bool { return !(*this == r); };
  auto operator<=(Rational const &r) const->bool { return !(*this > r); };
  auto operator>=(Rational const &r) const->bool { return !(*this < r); };
};

inline auto Rational::operator*=(Rational const &r) -> Rational {
  numerator *= r.numerator;
  denominator *= r.denominator;
  gcd = std::gcd(numerator, denominator);
  numerator /= gcd;
  denominator /= gcd;
  return *this;
}

inline auto Rational::operator/=(Rational const &r) -> Rational {
  numerator *= r.denominator;
  denominator *= r.numerator;
  gcd = std::gcd(numerator, denominator);
  numerator /= gcd;
  denominator /= gcd;
  return *this;
}


inline Rational::Rational(int n, int d) {
  if (d == 0) throw std::runtime_error("division by zero");
  gcd = std::gcd(n, d);
  numerator = n / gcd;
  denominator = d / gcd;
}

inline auto Rational::string() const -> std::string {
  return "num = " + std::to_string(numerator) + ", denominator = " + std::to_string(denominator) +
         ", gcd = " + std::to_string(gcd);
}

inline std::ostream &operator<<(std::ostream &os, Rational const &r) {
  return os << r.numerator << "//" << r.denominator;
}

inline auto Rational::operator+(Rational const &r) const -> Rational {
  auto m = denominator * r.denominator;
  auto n1 = numerator * r.denominator;
  auto n2 = r.numerator * denominator;
  return Rational(n1 + n2, m);
}

inline auto Rational::operator-(Rational const &r) const -> Rational { return *this + -r; }

inline auto Rational::operator*(Rational const &r) const -> Rational {
  return Rational(numerator * r.numerator, denominator * r.denominator);
}

inline auto Rational::operator/(Rational const &r) const -> Rational {
  return Rational(numerator * r.denominator, denominator * r.numerator);
}

inline auto Rational::operator==( Rational const &r) const -> bool {
  return (numerator == r.numerator) && (denominator == r.denominator);
}

inline auto Rational::operator<(Rational const &r) const -> bool {
  auto n = *this - r;
  return n.numerator < 0;
}

inline auto Rational::operator>(Rational const &r) const -> bool {
  auto n = *this - r;
  return n.numerator > 0;
}