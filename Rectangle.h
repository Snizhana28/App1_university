#include <iostream>
#include <algorithm>  
using namespace std;

class Rectangle {
private:
    double x;  
    double y;  
    double width;  
    double height; 

public:
    Rectangle(double x, double y, double width, double height)
        : x(x), y(y), width(width), height(height) {}

    void move(double dx, double dy) 
    {
        x += dx;
        y += dy;
    }

    void resize(double newWidth, double newHeight) 
    {
        width = newWidth;
        height = newHeight;
    }

    static Rectangle minimumBoundingRectangle(const Rectangle& rect1, const Rectangle& rect2) 
    {
        double minX = min(rect1.x, rect2.x);
        double minY = min(rect1.y, rect2.y);
        double maxX = max(rect1.x + rect1.width, rect2.x + rect2.width);
        double maxY = max(rect1.y + rect1.height, rect2.y + rect2.height);

        return Rectangle(minX, minY, maxX - minX, maxY - minY);
    }

    static Rectangle intersection(const Rectangle& rect1, const Rectangle& rect2) 
    {
        double interLeft = max(rect1.x, rect2.x);
        double interTop = max(rect1.y, rect2.y);
        double interRight = min(rect1.x + rect1.width, rect2.x + rect2.width);
        double interBottom = min(rect1.y + rect1.height, rect2.y + rect2.height);

        if (interLeft < interRight && interTop < interBottom) 
        {
            return Rectangle(interLeft, interTop, interRight - interLeft, interBottom - interTop);
        }
        else 
        {
            return Rectangle(0, 0, 0, 0);
        }
    }

    void display() const 
    {
        cout << "Rectangle: x=" << x << ", y=" << y << ", width=" << width << ", height=" << height << endl;
    }
};