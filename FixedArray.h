#include <iostream>
#include <cstring>
using namespace std;

const int MAX_LENGTH = 10;
const int MAX_SIZE = 2;

class FixedArray {
private: 
    char array[MAX_SIZE][MAX_LENGTH];
public:
    FixedArray() {
        for (int i = 0; i < MAX_SIZE; ++i) {
            strcpy(array[i], "");
        }
    }

    bool isValidIndex(int index) {
        return (index >= 0 && index < MAX_SIZE);
    }
    bool isValidLength(const char* value) {
        return (strlen(value) <= MAX_LENGTH - 2);
    }

    const char* getRow(int index) {
        if (isValidIndex(index)) {
            return array[index];
        }
        else {
            return "Invalid index";
        }
    }

    void setRow(int index, const char* value) {
        if (isValidIndex(index)) {
            strncpy(array[index], value, MAX_LENGTH - 1);
            array[index][MAX_LENGTH - 1] = '\0'; 
        }
        else {
            cout << "Invalid index" << endl;
        }
    }

    void displayElement(int index) {
        if (isValidIndex(index)) {
            cout << "Element at index " << index << ": " << array[index] << endl;
        }
        else {
            cout << "Invalid index" << endl;
        }
    }

    void displayArray() {
        cout << "Array content:" << endl;
        for (int i = 0; i < MAX_SIZE; ++i) {
            cout << "[" << i << "] " << array[i] << endl;
        }
    }

    FixedArray operator+(const FixedArray& other) {
        FixedArray result;
        for (int i = 0; i < MAX_SIZE; ++i) {
            if (isValidLength(result.array[i]) && isValidLength(other.array[i])) {
                strncat(result.array[i], array[i], MAX_LENGTH - strlen(result.array[i]) - 1);
                strncat(result.array[i], other.array[i], MAX_LENGTH - strlen(result.array[i]) - 1);
            }
            else {
                cout << "Invalid length during concatenation" << endl;
                break;  
            }
        }
        return result;
    }
    FixedArray operator-(const FixedArray& other) {
        FixedArray result;
        for (int i = 0; i < MAX_SIZE; ++i) {
            bool found = false;
            for (int j = 0; j < MAX_SIZE; ++j) {
                if (strcmp(array[i], other.array[j]) == 0) {
                    found = true;
                    break;
                }
            }
            if (!found && isValidLength(array[i])) {
                strncpy(result.array[i], array[i], MAX_LENGTH - 1);
                result.array[i][MAX_LENGTH - 1] = '\0';
            }
            else {
                cout << "Invalid length during subtraction" << endl;
                break;  
            }
        }
        return result;
    }
};