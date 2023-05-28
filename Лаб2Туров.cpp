#include <iostream>
#include <string>

using namespace std;

struct Pair {
    int first;
    unsigned int second;

    Pair(int f = 0, unsigned int s = 0) : first(f), second(s) {}
};

class Fraction {
private:
    int integer_part;
    unsigned int fractional_part;

public:
    Fraction(int i = 0, unsigned int f = 0) : integer_part(i), fractional_part(f) {}

    Fraction operator+(const Fraction& other) const {
        int new_integer_part = integer_part + other.integer_part;
        unsigned int new_fractional_part = fractional_part + other.fractional_part;

        if (new_fractional_part >= 1000000000) {
            new_integer_part++;
            new_fractional_part -= 1000000000;
        }

        return Fraction(new_integer_part, new_fractional_part);
    }

    Fraction operator-(const Fraction& other) const {
        int new_integer_part = integer_part - other.integer_part;
        unsigned int new_fractional_part = fractional_part - other.fractional_part;

        if (new_fractional_part >= 1000000000) {
            new_integer_part--;
            new_fractional_part += 1000000000;
        }

        return Fraction(new_integer_part, new_fractional_part);
    }

    Fraction operator*(const Fraction& other) const {
        long long int new_integer_part = integer_part * other.integer_part;
        unsigned long long int new_fractional_part = fractional_part * other.fractional_part;

        if (new_fractional_part >= 1000000000) {
            new_integer_part += new_fractional_part / 1000000000;
            new_fractional_part %= 1000000000;
        }

        return Fraction(new_integer_part, new_fractional_part);
    }

    bool operator==(const Fraction& other) const {
        return (integer_part == other.integer_part && fractional_part == other.fractional_part);
    }

    string toString() const {
        string result = to_string(integer_part);

        if (fractional_part > 0) {
            result += ".";

            string fractional_str = to_string(fractional_part);
            while (fractional_str.size() < 9) {
                fractional_str = "0" + fractional_str;
            }

            result += fractional_str;
        }

        return result;
    }
};

int main() {
    Fraction f1(1, 500000000);
    Fraction f2(2, 700000000);

    cout << "f1 = " << f1.toString() << endl;
    cout << "f2 = " << f2.toString() << endl;

    Fraction f3 = f1 + f2;
    cout << "f3 = f1 + f2 = " << f3.toString() << endl;

    Fraction f4 = f2 - f1;
    cout << "f4 = f2 - f1 = " << f4.toString() << endl;

    Fraction f5 = f1 * f2;
    cout << "f5 = f1 * f2 = " << f5.toString() << endl;

    bool equal = (f1 == f2);
    cout << "f1 == f2: " << (equal ? "true" : "false") << endl;

    equal = (f1 == Fraction(1, 500000000));
    cout << "f1 == 1.5: " << (equal ? "true" : "false") << endl;

    return 0;
}