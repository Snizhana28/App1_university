#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Record {
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

    Record(string last, string first, string dob, string phone)
        : lastName(last), firstName(first), dateOfBirth(dob), phoneNumber(phone) {}
};