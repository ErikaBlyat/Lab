#include <iostream>
using namespace std;

struct Pair {
    int first;
    int second;
};

class Fraction {
    Pair data;
public:
    Fraction(int num, int den = 1) {
        data.first = num;
        data.second = den;
    }
    Fraction() {
        data.first = 0;
        data.second = 1;
    }
    int numerator() const {
        return data.first;
    }
    int denominator() const {
        return data.second;
    }
    Fraction& operator+=(const Fraction& rhs) {
        data.first = data.first * rhs.data.second + rhs.data.first * data.second;
        data.second *= rhs.data.second;
        return *this;
    }
    Fraction& operator-=(const Fraction& rhs) {
        data.first = data.first * rhs.data.second - rhs.data.first * data.second;
        data.second *= rhs.data.second;
        return *this;
    }
    Fraction& operator*=(const Fraction& rhs) {
        data.first *= rhs.data.first;
        data.second *= rhs.data.second;
        return *this;
    }
    Fraction& operator/=(const Fraction& rhs) {
        data.first *= rhs.data.second;
        data.second *= rhs.data.first;
        return *this;
    }
};

Fraction operator+(Fraction lhs, const Fraction& rhs) {
    lhs += rhs;
    return lhs;
}

Fraction operator-(Fraction lhs, const Fraction& rhs) {
    lhs -= rhs;
    return lhs;
}

Fraction operator*(Fraction lhs, const Fraction& rhs) {
    lhs *= rhs;
    return lhs;
}

Fraction operator/(Fraction lhs, const Fraction& rhs) {
    lhs /= rhs;
    return lhs;
}

bool operator==(const Fraction& lhs, const Fraction& rhs) {
    return lhs.numerator() == rhs.numerator() && lhs.denominator() == rhs.denominator();
}

bool operator!=(const Fraction& lhs, const Fraction& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Fraction& lhs, const Fraction& rhs) {
    return lhs.numerator() * rhs.denominator() < rhs.numerator() * lhs.denominator();
}

bool operator<=(const Fraction& lhs, const Fraction& rhs) {
    return lhs.numerator() * rhs.denominator() <= rhs.numerator() * lhs.denominator();
}

bool operator>(const Fraction& lhs, const Fraction& rhs) {
    return lhs.numerator() * rhs.denominator() > rhs.numerator() * lhs.denominator();
}

bool operator>=(const Fraction& lhs, const Fraction& rhs) {
    return lhs.numerator() * rhs.denominator() >= rhs.numerator() * lhs.denominator();
}

ostream& operator<<(ostream& os, const Fraction& f) {
    os << f.numerator() << "/" << f.denominator();
    return os;
}

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3 = f1 + f2;
    Fraction f4 = f1 - f2;
    Fraction f5 = f1 * f2;
    Fraction f6 = f1 / f2;
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    cout << "f1 + f2 = " << f3 << endl;
    cout << "f1 - f2 = " << f4 << endl;
    cout << "f1 * f2 = " << f5 << endl;
    cout << "f1 / f2 = " << f6 << endl;
    if (f1 == f2) {
        cout << "f1 == f2" << endl;
    }
    if (f1 != f2) {
        cout << "f1 != f2" << endl;
    }
    if (f1 < f2) {
        cout << "f1 < f2" << endl;
    }
    if (f1 <= f2) {
        cout << "f1 <= f2" << endl;
    }
    if (f1 > f2) {
        cout << "f1 > f2" << endl;
    }
    if (f1 >= f2) {
        cout << "f1 >= f2" << endl;
    }
    return 0;
}