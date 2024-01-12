#include <iostream>
#include <cstring>
using namespace std;

const int MAX_LENGTH = 10;
const int MAX_SIZE = 2;

class DynamicArray {
private:
    char** array;  
    int size;      
public:
    DynamicArray() {
        size = MAX_SIZE;
        array = new char* [size]; 
        for (int i = 0; i < size; ++i) {
            array[i] = new char[MAX_LENGTH]; 
            strcpy(array[i], "");
        }
    }

    ~DynamicArray() {
        for (int i = 0; i < size; ++i) {
            delete[] array[i]; 
        }
        delete[] array;  
    }

    bool isValidIndex(int index) {
        return (index >= 0 && index < size);
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
        for (int i = 0; i < size; ++i) {
            cout << "[" << i << "] " << array[i] << endl;
        }
    }

    DynamicArray operator+(const DynamicArray& other) {
        DynamicArray result;
        for (int i = 0; i < size; ++i) {
            strcat(result.array[i], array[i]);
            strcat(result.array[i], other.array[i]);
        }
        return result;
    }

    DynamicArray operator-(const DynamicArray& other) {
        DynamicArray result;
        for (int i = 0; i < size; ++i) {
            char* token = strtok(array[i], " ");
            while (token != nullptr) {
                if (strstr(other.array[i], token) == nullptr) {
                    strcat(result.array[i], token);
                    strcat(result.array[i], " ");
                }
                token = strtok(nullptr, " ");
            }
            result.array[i][strlen(result.array[i]) - 1] = '\0';  
        }
        return result;
    }
};