#ifndef ULAMEK_HPP
#define ULAMEK_HPP

#include <iostream>

class Ulamek {
public:
    Ulamek(int a, int b);

    Ulamek operator+(const Ulamek& other) const;
    Ulamek operator-(const Ulamek& other) const;
    Ulamek operator*(const Ulamek& other) const;
    Ulamek operator/(const Ulamek& other) const;
    bool operator==(const Ulamek& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Ulamek& u) {
        os << u.a << "/" << u.b;
        return os;
    }

private:
    void optimize();
    int a;
    int b;
};
