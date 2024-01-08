#ifndef GeometricFigure_class
#define GeometricFigure_class
#include <iostream>
#include <cmath>
using namespace std;

class GeometricFigure abstract
{
protected:
    double x, y;

public:
    GeometricFigure(double x_, double y_) : x(x_), y(y_) {}

    virtual void move(double dx, double dy) {
        x += dx;
        y += dy;
    }

    virtual void resize(double scale) = 0;

    virtual void display() const = 0;
};
#endif 