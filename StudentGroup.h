#include "Student.h"

class StudentGroup
{
private:
	vector<Student> students;
public:
	StudentGroup() {}
	void addStudent(const Student& student)
	{
		students.push_back(student);
		cout << "Student added" << endl;
	}
	void removeStudent(const string& lastName)
	{
		auto it = find_if(students.begin(), students.end(), [&](const Student& r) {
			return r.getLastName() == lastName;
			});

		if (it != students.end()) {
			students.erase(it);
			cout << "Student removed" << endl;
		}
		else
		{
			cout << "Student not found" << endl;
		}
	}
    void searchByLastName(const string& lastName) {
        cout << "Students by surname " << lastName << ":\n";
        for (const Student& students : students) {
            if (students.getLastName() == lastName) {
                cout << "Surname: " << students.getLastName() << "\nName: " << students.getFirstName()
                    << "\nDate of birth: " << students.getDateOfBirth() << "\nPhone: " << students.getPhoneNumber() << "\n";
            }
        }
    }

    void sortByLastName() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getLastName() < b.getLastName();
            });

        cout << "Student group are sorted by last name.\n";
    }

    void displayStudent() {
        cout << "Student group:\n";
        for (const Student& students : students) {
            cout << "Surname: " << students.getLastName() << "\nName: " << students.getFirstName()
                << "\nDate of birth: " << students.getDateOfBirth() << "\nPhone: " << students.getPhoneNumber() << "\n";
        }
    }

    bool validateDateOfBirth(const string& dateOfBirth) {
        if (dateOfBirth.length() != 10) {
            return false;
        }
        if (dateOfBirth[2] != '.' || dateOfBirth[5] != '.') {
            return false;
        }
        for (int i = 0; i < dateOfBirth.length(); i++) {
            if (i == 2 || i == 5) {
                continue;
            }
            if (!isdigit(dateOfBirth[i])) {
                return false;
            }
        }
        int day = stoi(dateOfBirth.substr(0, 2));
        int month = stoi(dateOfBirth.substr(3, 2));
        int year = stoi(dateOfBirth.substr(6, 4));
        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2021) {
            return false;
        }
        return true;
    }
    bool validatePhoneNumber(const string& phoneNumber) {
        if (phoneNumber.length() != 19) {
            return false;
        }
        if (phoneNumber[0] != '+' || phoneNumber[1] != '3' || phoneNumber[2] != '8' || phoneNumber[3] != ' ' || phoneNumber[4] != '('
            || phoneNumber[8] != ')' || phoneNumber[9] != ' ' || phoneNumber[13] != '-' || phoneNumber[16] != '-') {
            return false;
        }
        for (int i = 0; i < phoneNumber.length(); i++)
        {
            if (i == 0 || i == 1 || i == 2 || i == 3 || i == 4 || i == 8 || i == 9 || i == 13 || i == 16) {
                continue;
            }
            if (!isdigit(phoneNumber[i])) {
                return false;
            }
        }
        return true;
    }
};