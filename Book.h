#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Book 
{
private:
    string title;
    string author;
    int year;

public:
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }

    Book(string t, string a, int y) : title(t), author(a), year(y) {}
};