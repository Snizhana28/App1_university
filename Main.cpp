#include "library.h"
#include "Stack.h"

int main() 
{
    Stack<int> train1, train2;
    char inputChoice;
    cout << "Enter '1' for input from file or '2' for keyboard input: ";
    cin >> inputChoice;
   
    switch (inputChoice) {
    case '1': {
        fstream file("wagon.txt");
        if (file.is_open()) {
            int wagon_number;
            while (file >> wagon_number) {
                if (wagon_number % 2 == 0) {
                    train1.push(wagon_number);
                }
                else {
                    train2.push(wagon_number);
                }
            }
            file.close();

            cout << "First train: ";
            train1.output();
            cout << "\nSecond train: ";
            train2.output();
        }
        else {
            cout << "Failed to open the file.\n";
        }
        break;

    }
    case '2': {
         int input_wagon;
         cout << "Enter wagon number (0 to finish): ";
        while (cin >> input_wagon && input_wagon != 0) {
        if (input_wagon % 2 == 0) {
            train1.push(input_wagon);
        }
        else {
            train2.push(input_wagon);
        }
        cout << "Enter wagon number (0 to finish): ";
        }

        cout << "First train: ";
        train1.output();
        cout << "\nSecond train: ";
        train2.output();
        break;
    }
    default:
        cout << "Invalid choice." << endl;
        return 1;
    }

    return 0;
}

