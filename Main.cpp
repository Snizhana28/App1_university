#include "Notebook.h"
int main()
{
    Notebook notebook;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Remove Record\n";
        cout << "3. Search by Last Name\n";
        cout << "4. Sort by Last Name\n";
        cout << "5. Display Notebook\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string last, first, dob, phone;

            cout << "Enter last name: ";
            cin >> last;
            cout << "Enter first name: ";
            cin >> first;
            cout << "Enter date of birth (DD.MM.YYYY): ";
            cin >> dob;

            while (!notebook.validateDateOfBirth(dob)) {
                cout << "Invalid date format. Please enter date of birth (DD.MM.YYYY): ";
                cin >> dob;
            }
            cin.ignore();

            cout << "Enter phone number +38 (0XX) XXX-XX-XX: ";
            getline(cin, phone);

            while (!notebook.validatePhoneNumber(phone)) {
                cout << "Invalid phone number format. Please enter phone number +38 (0XX) XXX-XX-XX: ";
                getline(cin, phone); 
                cin.ignore();
            }
            
            Record newRecord(last, first, dob, phone);
            notebook.addRecord(newRecord);
            break;
        }
        case 2: {
            string lastName;
            cout << "Enter last name to remove: ";
            cin >> lastName;
            notebook.removeRecord(lastName);
            break;
        }
        case 3: {
            string lastName;
            cout << "Enter last name to search: ";
            cin >> lastName;
            notebook.searchByLastName(lastName);
            break;
        }
        case 4:
            notebook.sortByLastName();
            break;
        case 5:
            notebook.displayNotebook();
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

	return 0;
}
