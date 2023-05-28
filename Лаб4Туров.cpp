#include <iostream> 
#include <cmath> 

using namespace std;


class RealNumber {
protected:
    double value;

public:

    RealNumber(double val) {
        value = val;
    }


    virtual double calculateModulus() {
        return abs(value);
    }


    virtual void print() {
        cout << "Value: " << value << endl;
        cout << "Modulus: " << calculateModulus() << endl;
    }
};


class ComplexNumber : public RealNumber {
private:
    double imaginaryPart;

public:

    ComplexNumber(double real, double imaginary) : RealNumber(real) {
        imaginaryPart = imaginary;
    }


    double calculateModulus() override {
        return sqrt(value * value + imaginaryPart * imaginaryPart);
    }


    void print() override {
        cout << "Real Part: " << value << endl;
        cout << "Imaginary Part: " << imaginaryPart << endl;
        cout << "Modulus: " << calculateModulus() << endl;
    }
};

int main() {
    RealNumber realNum(3.14);
    realNum.print();

    ComplexNumber complexNum(2.0, 4.0);
    complexNum.print();


    RealNumber* numberPtr = &complexNum;
    numberPtr->print();

    return 0;
}