#include "Ulamek.hpp"
#include <numeric>
#include <cstdlib>
#include <stdexcept>

Ulamek::Ulamek(int a, int b)
    : a(a), b(b)
{
    if (b == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    optimize();
}

Ulamek Ulamek::operator+(const Ulamek& other) const {
    int new_a = this->a * other.b + other.a * this->b;
    int new_b = this->b * other.b;
    return Ulamek(new_a, new_b);
}

Ulamek Ulamek::operator-(const Ulamek& other) const {
    int new_a = this->a * other.b - other.a * this->b;
    int new_b = this->b * other.b;
    return Ulamek(new_a, new_b);
}

Ulamek Ulamek::operator*(const Ulamek& other) const {
    int new_a = this->a * other.a;
    int new_b = this->b * other.b;
    return Ulamek(new_a, new_b);
}

Ulamek Ulamek::operator/(const Ulamek& other) const {
    if (other.a == 0) {
        throw std::invalid_argument("Division by zero (other numerator is zero).");
    }
    int new_a = this->a * other.b;
    int new_b = this->b * other.a;
    return Ulamek(new_a, new_b);
}

bool Ulamek::operator==(const Ulamek& other) const {
    return (this->a == other.a) && (this->b == other.b);
}

void Ulamek::optimize() {
    if (b < 0) {
        a = -a;
        b = -b;
    }
    int gcd = std::gcd(std::abs(a), std::abs(b));
    if (gcd > 1) {
        a /= gcd;
        b /= gcd;
    }
}