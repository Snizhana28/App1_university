#include <iostream>
#include <cmath>

using namespace std;

class Vector3D {
private:
    double x;
    double y;
    double z;

public:
    Vector3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

    Vector3D add(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D subtract(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    double dotProduct(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    double length() const {
        return sqrt(x * x + y * y + z * z);
    }

    double cosineAngle(const Vector3D& other) const {
        double dot = dotProduct(other);
        double lengthProduct = length() * other.length();

        if (lengthProduct == 0) {
            cerr << "Cannot calculate angle. One or both vectors have zero length." << endl;
            return 0.0;
        }

        return dot / lengthProduct;
    }

    void display() const {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }
};
