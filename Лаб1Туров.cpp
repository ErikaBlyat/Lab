#include <iostream>
using namespace std;

struct Pair {
    int first;
    unsigned int second;
    Pair(int f = 0, unsigned int s = 0) {
        first = f;
        second = s;
    }
};

class Fraction {
private:
    int wholePart;
    unsigned int fractionalPart;

public:
    Fraction(int wp = 0, unsigned int fp = 0) {
        wholePart = wp;
        fractionalPart = fp;
    }

    Fraction operator+(const Fraction& other) {
        int newWholePart = wholePart + other.wholePart;
        unsigned int newFractionalPart = fractionalPart + other.fractionalPart;
        if (newFractionalPart >= 1000000000) {
            newWholePart++;
            newFractionalPart -= 1000000000;
        }
        return Fraction(newWholePart, newFractionalPart);
    }

    Fraction operator-(const Fraction& other) {
        int newWholePart = wholePart - other.wholePart;
        unsigned int newFractionalPart = fractionalPart - other.fractionalPart;
        if (newFractionalPart > fractionalPart) {
            newWholePart--;
            newFractionalPart += 1000000000;
        }
        return Fraction(newWholePart, newFractionalPart);
    }

    Fraction operator*(const Fraction& other) {
        int newWholePart = (wholePart * other.wholePart) + ((fractionalPart * other.wholePart) / 1000000000)
            + ((other.fractionalPart * wholePart) / 1000000000);
        unsigned int newFractionalPart = (fractionalPart * other.fractionalPart) % 1000000000;
        return Fraction(newWholePart, newFractionalPart);
    }

    bool operator==(const Fraction& other) {
        return (wholePart == other.wholePart && fractionalPart == other.fractionalPart);
    }

    string toString() {
        string result = to_string(wholePart);
        if (fractionalPart > 0) {
            result += ".";
            string fractional = to_string(fractionalPart);
            while (fractional.length() < 9) {
                fractional = "0" + fractional;
            }
            result += fractional;
        }
        return result;
    }
};

int main() {
    Fraction f1(2, 500000000);
    Fraction f2(3, 750000000);

    Fraction sum = f1 + f2;
    Fraction diff = f1 - f2;
    Fraction prod = f1 * f2;

    cout << "f1: " << f1.toString() << endl;
    cout << "f2: " << f2.toString() << endl;
    cout << "sum: " << sum.toString() << endl;
    cout << "diff: " << diff.toString() << endl;
    cout << "prod: " << prod.toString() << endl;

    if (f1 == f2) {
        cout << "f1 and f2 are equal" << endl;
    }
    else {
        cout << "f1 and f2 are not equal" << endl;
    }

    return 0;
}