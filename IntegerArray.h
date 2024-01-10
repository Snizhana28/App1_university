#include <iostream>
#include <vector>
using namespace std;

class IntegerArray
{
private:
    vector<int> array;

public:
    IntegerArray(int start_index, int end_index) {
        if (start_index > end_index) {
            throw invalid_argument("The initial index must be less than or equal to the final index.");
        }

        array.resize(end_index - start_index + 1);
    }

    int& operator[](int index) {
        if(index < 0 || index >= array.size())
        {
            throw out_of_range("Going beyond the array.");
        }

        return array[index];
    }

    IntegerArray operator+(const IntegerArray& other) const {
        IntegerArray result(0, array.size() - 1);

        for (size_t i = 0; i < array.size(); ++i) {
            result[i] = array[i] + other.array[i];
        }

        return result;
    }

    IntegerArray operator-(const IntegerArray& other) const {
        IntegerArray result(0, array.size() - 1);

        for (size_t i = 0; i < array.size(); ++i) {
            result[i] = array[i] - other.array[i];
        }

        return result;
    }

    IntegerArray operator*(int scalar) const {
        IntegerArray result(0, array.size() - 1);

        for (size_t i = 0; i < array.size(); ++i) {
            result[i] = array[i] * scalar;
        }

        return result;
    }

    IntegerArray operator/(int scalar) const {
        if (scalar == 0) {
            throw invalid_argument("Division by zero is not possible.");
        }

        IntegerArray result(0, array.size() - 1);

        for (size_t i = 0; i < array.size(); ++i) {
            result[i] = array[i] / scalar;
        }

        return result;
    }

    void printElement(int index) const {
        cout << "Element with an index " << index << ": " << array[index] << endl;
    }

    void printArray() const {
        cout << "Array: ";
        for (size_t i = 0; i < array.size(); ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};
