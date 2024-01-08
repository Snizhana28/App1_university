#include "../App1_university/parent/GeometricFigure.h"
class Square : public GeometricFigure 
{
private:
    double side;

public:
    Square(double x_, double y_, double side_) : GeometricFigure(x_, y_), side(side_) {}

    void resize(double scale) override {
        side *= scale;
    }

    void display() const override {
        std::cout << "Square at (" << x << ", " << y << ") with side length " << side << std::endl;
    }
};