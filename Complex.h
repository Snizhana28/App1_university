#include <iostream>
using namespace std;

class Complex
{
private:
    double x;
    double y;

public:
    Complex() = default;
    Complex(double x, double y) : x(x), y(y) {}
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    void print() const;
    ~Complex() = default;

    friend Complex operator+(const Complex& complex1, const Complex& complex2);
    friend Complex operator-(const Complex& complex1, const Complex& complex2);
    friend Complex operator*(const Complex& complex1, const Complex& complex2);
    friend Complex operator/(const Complex& complex1, const Complex& complex2);
};