#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "FixedArray.h"
using namespace std;

int main()
{
    FixedArray array1, array2, result;
    int choice;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Set row in array1" << endl;
        cout << "2. Set row in array2" << endl;
        cout << "3. Display array1" << endl;
        cout << "4. Display array2" << endl;
        cout << "5. Display element in array1" << endl;
        cout << "6. Display element in array2" << endl;
        cout << "7. Concatenate arrays (array1 + array2)" << endl;
        cout << "8. Subtract arrays (array1 - array2)" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int index;
            char value[MAX_LENGTH];

            cout << "Enter index: ";
            cin >> index;
            cin.ignore();
            cout << "Enter value: ";
            cin.getline(value, MAX_LENGTH);

            if (array1.isValidIndex(index) && array1.isValidLength(value)) {
                array1.setRow(index, value);
                cout << "Row set successfully in array1." << endl;
            }
            else {
                cout << "Invalid. Row not set in array1." << endl;
            }
            break;
        }
        case 2: {
            int index;
            char value[MAX_LENGTH];

            cout << "Enter index: ";
            cin >> index;
            cin.ignore();
            cout << "Enter value: ";
            cin.getline(value, MAX_LENGTH);

            if (array2.isValidIndex(index) && array2.isValidLength(value)) {
                array2.setRow(index, value);
                cout << "Row set successfully in array2." << endl;
            }
            else {
                cout << "Invalid. Row not set in array2." << endl;                
            }
            break;
        }
        case 3:
            array1.displayArray();
            break;
        case 4:
            array2.displayArray();
            break;
        case 5: {
            int index;
            cout << "Enter index: ";
            cin >> index;

            array1.displayElement(index);
            break;
        }
        case 6: {
            int index;
            cout << "Enter index: ";
            cin >> index;

            array2.displayElement(index);
            break;
        }
        case 7:
            result = array1 + array2;
            cout << "Arrays concatenated successfully." << endl;
            result.displayArray();
            break;
        case 8:
            result = array1 - array2;
            cout << "Arrays subtracted successfully." << endl;
            result.displayArray();
            break;
        case 0:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
	return 0;
}
