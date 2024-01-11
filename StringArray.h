#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class StringArray {
private:
    int size;          
    char** array;      
    int* lengths;      

public:
    StringArray(int size) : size(size) {
        array = new char* [size];
        lengths = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = nullptr;
            lengths[i] = 0;
        }
    }
    ~StringArray() {
        for (int i = 0; i < size; ++i) {
            delete[] array[i];
        }
        delete[] array;
        delete[] lengths;
    }

    void addString(int index, const char* str) {
        if (index < 0 || index >= size) {
            std::cerr << "Invalid index\n";
            return;
        }
        delete[] array[index];
        lengths[index] = strlen(str);
        array[index] = new char[lengths[index] + 1];
        strcpy(array[index], str);
    }

    void printString(int index) const {
        if (index < 0 || index >= size || array[index] == nullptr) {
            std::cerr << "Invalid index or empty string\n";
            return;
        }

        std::cout << "String at index " << index << ": " << array[index] << std::endl;
    }

    void printArray() const {
        for (int i = 0; i < size; ++i) {
            std::cout << "String at index " << i << ": ";
            if (array[i] != nullptr) {
                std::cout << array[i];
            }
            else {
                std::cout << "null";
            }
            std::cout << std::endl;
        }
    }
    StringArray* concatenate(const StringArray& other) const {
		StringArray* result = new StringArray(size + other.size);
        for (int i = 0; i < size; ++i) {
			result->addString(i, array[i]);
		}
        for (int i = 0; i < other.size; ++i) {
			result->addString(size + i, other.array[i]);
		}
		return result;
	}
    StringArray* merge(const StringArray& other) const {
		StringArray* result = new StringArray(size + other.size);
        for (int i = 0; i < size; ++i) {
			result->addString(i, array[i]);
		}
        for (int i = 0; i < other.size; ++i) {
			bool found = false;
            for (int j = 0; j < size; ++j) {
                if (strcmp(other.array[i], array[j]) == 0) {
					found = true;
					break;
				}
			}
            if (!found) {
				result->addString(size + i, other.array[i]);
			}
		}
		return result;
	}
};