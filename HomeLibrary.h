#include "Book.h"

class HomeLibrary
{
private:
    vector<Book> library;

public:
    void addBook(const Book& book) {
        library.push_back(book);
        cout << "Book added to the library.\n";
    }

    void removeBook(const string& title) {
        auto it = find_if(library.begin(), library.end(), [&](const Book& b) {
            return b.getTitle() == title;
        });

        if (it != library.end()) {
            library.erase(it);
            cout << "The book has been removed from the library.\n";
        }
        else {
            cout << "Book not found in the library.\n";
        }
    }

    void searchByAuthor(const string& author) {
        cout << "Books by the author " << author << ":\n";
        for (const Book& book : library) {
            if (book.getAuthor() == author) {
                cout << "Title: " << book.getTitle() << ", Year of publication: " << book.getYear() << "\n";
            }
        }
    }

    void sortByYear() {
        sort(library.begin(), library.end(), [](const Book& a, const Book& b) 
        {
            return a.getYear() < b.getYear();
        });

        cout << "The library is sorted by year of publication.\n";
    }

    void displayLibrary() {
        cout << "Library:\n";
        for (const Book& book : library) {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Year of publication: " << book.getYear() << "\n";
        }
    }
};