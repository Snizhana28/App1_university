#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Student
{
private:
    string lastName;
    string firstName;
    string dateOfBirth;
    string phoneNumber;

public:
    Student(string lastName, string firstName, string dateOfBirth, string phoneNumber) 
        : lastName(lastName), firstName(firstName), dateOfBirth(dateOfBirth), phoneNumber(phoneNumber) {}
    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getDateOfBirth() const { return dateOfBirth; }
    string getPhoneNumber() const { return phoneNumber; }

};