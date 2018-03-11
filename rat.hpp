#include <iostream>
#include <string>

const class Rational {
    const int num, den, gcd;

    int calc_gcd(int, int);
    friend std::ostream &operator<<(std::ostream &os, Rational const &r);

  public:
    Rational(int n, int d, int g) : num(n), den(d), gcd(g){};
    Rational(int, int);
    Rational(int n): Rational(n, 1, 1) {};
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

Rational::Rational(int n, int d) {
    if (d == 0) {
        std::cerr << "Division by zero error." << std::endl;
        abort();
    }
    auto g = abs(calc_gcd(n, d));
    if (d < 0) {
        n = -n;
        d = -d;
    }
    Rational(n / g, d / g, g);
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