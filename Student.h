#include <iostream>
using namespace std;

class Student
{
private:
    string lastName;
    string firstName;
    string dateOfBirth;
    string phoneNumber;

public:
    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getDateOfBirth() const { return dateOfBirth; }
    string getPhoneNumber() const { return phoneNumber; }
};