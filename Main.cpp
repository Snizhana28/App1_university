#include "Address.h"

int main()
{
    Address organizationAddress("Main Street", "Cityville", "12345");

    int choice;
    do {
        cout << "Choose an option:" << endl;
        cout << "1. Display address" << endl;
        cout << "2. Change address" << endl;
        cout << "3. Exit" << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Displaying address:" << endl;
            organizationAddress.display();
            break;
        case 2:
        {
            string newStreet, newCity, newPostalCode;
            cout << "Enter new street: ";
            cin >> newStreet;
            cout << "Enter new city: ";
            cin >> newCity;
            cout << "Enter new postal code: ";
            cin >> newPostalCode;

            organizationAddress.changeAddress(newStreet, newCity, newPostalCode);
            cout << "Address changed successfully." << endl;
        }
        break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }

    } while (choice != 3);
	return 0;
}
