#include "../App1_university/Complex.h"

int main()
{
    Complex complex1(1.0, 2.0);
    Complex complex2(2.0, 3.0);

    cout << "Complex 1: ";
    complex1.print();
    cout << "Complex 2: ";
    complex2.print();
    cout << "Complex 1 + Complex 2: ";
    (complex1 + complex2).print();
    cout << "Complex 1 - Complex 2: ";
    (complex1 - complex2).print();
    cout << "Complex 1 * Complex 2: ";
    (complex1 * complex2).print();
    cout << "Complex 1 / Complex 2: ";
    (complex1 / complex2).print();
	return 0;
}
