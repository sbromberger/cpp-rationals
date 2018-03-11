#include <iostream>
#include <string>

class Rational {
    const int gcd, num, den;

    int calc_gcd(int, int);
    friend std::ostream &operator<<(std::ostream &os, Rational const &r);

  public:
    Rational(int n, int d, int g) : gcd{g}, num{n}, den{d}{};
    Rational(int, int);
    Rational(int n): Rational(1, n, 1) {};
    std::string string();
    Rational operator+(Rational);
    Rational operator-() { return {-num, den}; };
    Rational operator-(Rational);
    Rational operator*(Rational);
    Rational operator/(Rational);
};

int Rational::calc_gcd(int n, int d) {
    int a = n, b = d;
    while (b != 0) {
        auto m = a % b;
        a = b;
        b = m;
    }
    return a;
}

Rational::Rational(int n, int d):gcd{Rational::calc_gcd(n, d)}, num{n / gcd}, den{d / gcd}{
    if (d == 0) {
        std::cerr << "Division by zero error." << std::endl;
        abort();
    }
}

std::string Rational::string() {
    return "num = " + std::to_string(num) + ", den = " + std::to_string(den) + ", gcd = " + std::to_string(gcd);
}

std::ostream &operator<<(std::ostream &os, Rational const &r) {
    return os << r.num << "//" << r.den;
}

Rational Rational::operator+(Rational r) {
    auto m = den * r.den;
    auto n1 = num * r.den;
    auto n2 = r.num * den;
    return Rational(n1 + n2, m);
}

Rational Rational::operator-(Rational r) {
    return *this + -r;
}

Rational Rational::operator*(Rational r) {
    return Rational(num * r.num, den * r.den);
}

Rational Rational::operator/(Rational r) {
    return Rational(num * r.den, den * r.num);
}