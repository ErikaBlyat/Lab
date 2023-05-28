#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

class Conus {
protected:
    double r, H;
public:
    Conus(double radius, double height) {
        r = radius;
        H = height;
    }
    double baseArea() const {
        return M_PI * r * r;
    }
    double lateralSurfaceArea() const {
        return M_PI * r * sqrt(r * r + H * H);
    }
    double totalSurfaceArea() const {
        return lateralSurfaceArea() + baseArea();
    }
    double volume() const {
        return (1.0 / 3.0) * M_PI * r * r * H;
    }
    double weight() const {
        //assuming density of the material is 1
        return volume();
    }
};

class CutConus : public Conus {
public:
    CutConus(double radius, double height) : Conus(radius, height / 2) {}
};

int main() {
    Conus c1(5.0, 10.0);
    CutConus c2(5.0, 10.0);

    cout << "Object 1 - Original Cone:" << endl;
    cout << "Base Area: " << c1.baseArea() << endl;
    cout << "Lateral Surface Area: " << c1.lateralSurfaceArea() << endl;
    cout << "Total Surface Area: " << c1.totalSurfaceArea() << endl;
    cout << "Volume: " << c1.volume() << endl;
    cout << "Weight: " << c1.weight() << endl;

    cout << "\nObject 2 - Cut Cone:" << endl;
    cout << "Base Area: " << c2.baseArea() << endl;
    cout << "Lateral Surface Area: " << c2.lateralSurfaceArea() << endl;
    cout << "Total Surface Area: " << c2.totalSurfaceArea() << endl;
    cout << "Volume: " << c2.volume() << endl;
    cout << "Weight: " << c2.weight() << endl;

    double baseAreaRatio = c2.baseArea() / c1.baseArea();
    double lateralSurfaceAreaRatio = c2.lateralSurfaceArea() / c1.lateralSurfaceArea();
    double totalSurfaceAreaRatio = c2.totalSurfaceArea() / c1.totalSurfaceArea();
    double volumeRatio = c2.volume() / c1.volume();
    double weightRatio = c2.weight() / c1.weight();

    cout << "\nRatios:" << endl;
    cout << "Base Area Ratio: " << baseAreaRatio << endl;
    cout << "Lateral Surface Area Ratio: " << lateralSurfaceAreaRatio << endl;
    cout << "Total Surface Area Ratio: " << totalSurfaceAreaRatio << endl;
    cout << "Volume Ratio: " << volumeRatio << endl;
    cout << "Weight Ratio: " << weightRatio << endl;

    return 0;
}