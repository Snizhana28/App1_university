#include "Record.h"

class Notebook {
private:
    vector<Record> records;

public:
    void addRecord(const Record& record) {
        records.push_back(record);
        cout << "The entry is added to the notebook.\n";
    }

    void removeRecord(const string& lastName) {
        auto it = find_if(records.begin(), records.end(), [&](const Record& r) {
            return r.getLastName() == lastName;
            });

        if (it != records.end()) {
            records.erase(it);
            cout << "The entry is deleted from the notebook.\n";
        }
        else {
            cout << "The entry was not found in the notebook.\n";
        }
    }

    void searchByLastName(const string& lastName) {
        cout << "Records by surname " << lastName << ":\n";
        for (const Record& record : records) {
            if (record.getLastName() == lastName) {
                cout << "Surname: " << record.getLastName() << "\nName: " << record.getFirstName()
                    << "\nDate of birth: " << record.getDateOfBirth() << "\nPhone: " << record.getPhoneNumber() << "\n";
            }
        }
    }

    void sortByLastName() {
        sort(records.begin(), records.end(), [](const Record& a, const Record& b) {
            return a.getLastName() < b.getLastName();
            });

        cout << "Records are sorted by last name.\n";
    }

    void displayNotebook() {
        cout << "Notebook:\n";
        for (const Record& record : records) {
            cout << "Surname: " << record.getLastName() << "\nName: " << record.getFirstName()
                << "\nDate of birth: " << record.getDateOfBirth() << "\nPhone: " << record.getPhoneNumber() << "\n";
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