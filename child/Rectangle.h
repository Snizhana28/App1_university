#include "../App1_university/parent/GeometricFigure.h"
class Rectangle : public GeometricFigure 
{
private:
    double length, width;

public:
    Rectangle(double x_, double y_, double length_, double width_) : GeometricFigure(x_, y_), length(length_), width(width_) {}

    void resize(double scale) override {
        length *= scale;
        width *= scale;
    }

    void display() const override {
        std::cout << "Rectangle at (" << x << ", " << y << ") with length " << length << " and width " << width << std::endl;
    }
};