#include "Complex.h"

double Complex::getX() const
{
    return x;
}

double Complex::getY() const
{
    return y;
}

void Complex::setX(double x)
{
    this->x = x;
}

void Complex::setY(double y)
{
    this->y = y;
}

void Complex::print() const
{
    cout << x << " + " << y << "i" << endl;
}

Complex operator+(const Complex& complex1, const Complex& complex2)
{
    return Complex(complex1.x + complex2.x, complex1.y + complex2.y);
}

Complex operator-(const Complex& complex1, const Complex& complex2)
{
    return Complex(complex1.x - complex2.x, complex1.y - complex2.y);
}

Complex operator*(const Complex& complex1, const Complex& complex2)
{
    double x = complex1.x * complex2.x - complex1.y * complex2.y;
    double y = complex1.x * complex2.y + complex1.y * complex2.x;
    return Complex(x, y);
}

Complex operator/(const Complex& complex1, const Complex& complex2)
{
    double z = complex2.x * complex2.x + complex2.y * complex2.y;
    double x = (complex1.x * complex2.x + complex1.y * complex2.y) / z;
    double y = (complex1.y * complex2.x - complex1.x * complex2.y) / z;
    return Complex(x, y);
}