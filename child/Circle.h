#include "../App1_university/parent/GeometricFigure.h"
class Circle : public GeometricFigure 
{
private:
    double radius;

public:
    Circle(double x_, double y_, double radius_) : GeometricFigure(x_, y_), radius(radius_) {}

    void resize(double scale) override {
        radius *= scale;
    }

    void display() const override {
        std::cout << "Circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }
};