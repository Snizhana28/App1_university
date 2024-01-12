#include "HomeLibrary.h"

int main()
{
    HomeLibrary myLibrary;

    while (true) {
        cout << "Select an option:\n";
        cout << "1. Add a book";
        cout << "2. Delete a book";
        cout << "3. Search for a book by author";
        cout << "4. Sort books by year of publication\n";
        cout << "5. Show all books in the library\n";
        cout << "6. Exit\n";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string title, author;
            int year;

            cout << "Enter the title of the book: ";
            cin.ignore();
            getline(cin, title);

            cout << "Enter the author's name: ";
            getline(cin, author);

            cout << "Enter the year of publication: ";
            cin >> year;

            myLibrary.addBook(Book(title, author, year));
            break;
        }

        case 2: {
            string title;
            cout << "Enter the name of the book to delete: ";
            cin.ignore();
            getline(cin, title);
            myLibrary.removeBook(title);
            break;
        }

        case 3: {
            string author;
            cout << "Enter the author's name to search: ";
            cin.ignore();
            getline(cin, author);
            myLibrary.searchByAuthor(author);
            break;
        }

        case 4:
            myLibrary.sortByYear();
            break;

        case 5:
            myLibrary.displayLibrary();
            break;

        case 6:
            cout << "Exiting program!\n";
            return 0;

        default:
            cout << "Wrong choice. Please try again.\n";
        }
    }
	return 0;
}
