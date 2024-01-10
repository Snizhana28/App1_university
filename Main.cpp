#include "../App1_university/IntegerArray.h"

int main()
{
    try 
    {
        IntegerArray array1(1, 5);
        array1[1] = 10;
        array1[2] = 20;
        array1[3] = 30;

        IntegerArray array2(1, 5);
        array2[1] = 5;
        array2[2] = 10;
        array2[3] = 15;

        IntegerArray sum = array1 + array2;
        IntegerArray difference = array1 - array2;
        IntegerArray product = array1 * 2;
        IntegerArray quotient = array1 / 2;

        array1.printArray();
        array2.printArray();

        sum.printArray();
        difference.printArray();
        product.printArray();
        quotient.printArray();

        array1.printElement(2);
    }
    catch (const exception& e) 
    {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
	return 0;
}
