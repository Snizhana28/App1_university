#include <iostream>
#include <cmath> 
using namespace std;

class Polynomial {
private:
    int degree;
    int* coefficients;

public:
    Polynomial(int degree, int* coefficients) {
        if (degree < 0) {
            cerr << "Error: Degree cannot be negative." << endl;
            exit(EXIT_FAILURE);
        }

        this->degree = degree;
        this->coefficients = new int[degree + 1];
        for (int i = 0; i < degree + 1; i++) {
            this->coefficients[i] = coefficients[i];
        }
    }

    int calculate(int x) {
        int result = 0;
        int power = 1;
        for (int i = 0; i < degree + 1; i++) {
            result += coefficients[i] * power;
            power *= x;
        }
        return result;
    }

    Polynomial operator+(const Polynomial& other) {
        int newDegree = max(degree, other.degree);
        int* newCoefficients = new int[newDegree + 1]();

        for (int i = 0; i < degree + 1; i++) {
            newCoefficients[i] += coefficients[i];
        }

        for (int i = 0; i < other.degree + 1; i++) {
            newCoefficients[i] += other.coefficients[i];
        }

        return Polynomial(newDegree, newCoefficients);
    }

    Polynomial operator-(const Polynomial& other) {
        int newDegree = max(degree, other.degree);
        int* newCoefficients = new int[newDegree + 1]();

        for (int i = 0; i < degree + 1; i++) {
            newCoefficients[i] += coefficients[i];
        }

        for (int i = 0; i < other.degree + 1; i++) {
            newCoefficients[i] -= other.coefficients[i];
        }

        return Polynomial(newDegree, newCoefficients);
    }

    Polynomial operator*(const Polynomial& other) {
        int newDegree = degree + other.degree;
        int* newCoefficients = new int[newDegree + 1]();

        for (int i = 0; i < degree + 1; i++) {
            for (int j = 0; j < other.degree + 1; j++) {
                newCoefficients[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(newDegree, newCoefficients);
    }

    void print() {
        for (int i = degree; i >= 0; i--) {
            if (coefficients[i] != 0) {
                if (coefficients[i] > 0 && i < degree) {
                    cout << "+";
                }
                cout << coefficients[i];

                if (i > 0) {
                    cout << "x^" << i;
                }
            }
        }
        cout << endl;
    }

    ~Polynomial() {
        delete[] coefficients;
    }
};