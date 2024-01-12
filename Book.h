#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Book 
{
public:
    string title;
    string author;
    int year;

    Book(string t, string a, int y) : title(t), author(a), year(y) {}
};