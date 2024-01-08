#include <iostream>
#include <string>

using namespace std;

class Address {
private:
    string street;
    string city;
    string postalCode;

public:
    Address(const string& street_, const string& city_, const string& postalCode_)
        : street(street_), city(city_), postalCode(postalCode_) {}

    void changeAddress(const string& newStreet, const string& newCity, const string& newPostalCode) {
        street = newStreet;
        city = newCity;
        postalCode = newPostalCode;
    }

    void display() const {
        cout << "Street: " << street << endl;
        cout << "City: " << city << endl;
        cout << "Postal Code: " << postalCode << endl;
    }
};