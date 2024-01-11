#include "StringArray.h"

int main()
{
    int arraySize;
    std::cout << "Enter the size of the StringArray: ";
    std::cin >> arraySize;

    StringArray arr1(arraySize);
    StringArray arr2(arraySize);

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add String\n";
        std::cout << "2. Print String\n";
        std::cout << "3. Print Array\n";
        std::cout << "4. Concatenate Arrays\n";
        std::cout << "5. Merge Arrays\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int index;
            char str[100];
            std::cout << "Enter index and string to add: ";
            std::cin >> index >> str;
            arr1.addString(index, str);
            break;
        }
        case 2: {
            int index;
            std::cout << "Enter index to print: ";
            std::cin >> index;
            arr1.printString(index);
            break;
        }
        case 3:
            arr1.printArray();
            break;
        case 4: {
            StringArray* concatenated = arr1.concatenate(arr2);
            std::cout << "Concatenated Arrays:\n";
            concatenated->printArray();
            delete concatenated;
            break;
        }
        case 5: {
            StringArray* merged = arr1.merge(arr2);
            std::cout << "Merged Arrays:\n";
            merged->printArray();
            delete merged;
            break;
        }
        case 0:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 0);
	return 0;
}

