#include "../App1_university/Polynomial.h"
int main() 
{
    int coefficients1[] = { 1, 2, 3 };
    int coefficients2[] = { 4, 5, 0 };
    Polynomial p1(2, coefficients1);
    Polynomial p2(2, coefficients2);

    cout << "Polynomial 1: ";
    p1.print();
    cout << "Polynomial 2: ";
    p2.print();

    Polynomial sum = p1 + p2;
    cout << "Sum: ";
    sum.print();

    Polynomial difference = p1 - p2;
    cout << "Difference: ";
    difference.print();

    Polynomial product = p1 * p2;
    cout << "Product: ";
    product.print();

    int x = 2;
    cout << "p1(" << x << ") = " << p1.calculate(x) << endl;

    return 0;
}