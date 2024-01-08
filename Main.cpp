#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

template <typename T> 
class Stack {
private:
    T* conatiner;
    int top_elem;
    int size;
    void extend_memmory(int step_extend = 10) {
        size += step_extend;
        T* temp = new T[size];
        for (int i = 0; i < top_elem; i++) {
            temp[i] = conatiner[i];
        }
        delete[] conatiner;
        conatiner = temp;
    }

public:
    Stack() {
        top_elem = -1;
        size = 10;
        this->conatiner = new T[size];
    }
    Stack(int size) : conatiner() {
        this->size = size;
        this->conatiner = new T[size];
    }
    ~Stack() { delete[] conatiner; }

    void push(T elem) {
        if (isFull()) {
            extend_memmory();
        }
        top_elem++;
        conatiner[top_elem] = elem;
    }
    T pop() {
        if (isEmpty()) {
            return 0;
        }
        else {
            top_elem--;
            T* temp = new T[size];
            for (size_t i = 0; i <= top_elem; i++) {
                temp[i] = conatiner[i];
            }
            delete[] conatiner;
            conatiner = temp;
        }
    }
    T top() { 
        return conatiner[top_elem];         
    }
    void output() {
        for (size_t i = 0; i <= top_elem; i++) {
            if (conatiner[i] == conatiner[top_elem]) {
                cout << conatiner[i] << " ";
            }
            else {
                cout << conatiner[i] << " ";
            }
        }
    }
    bool isEmpty() {return (top_elem == -1) ? true : false; }
    bool isFull() { return (top_elem == size) ? true : false; }
};

int main() 
{
    Stack<int> train1, train2;
    char inputChoice;
    cout << "Enter '1' for input from file or '2' for keyboard input: ";
    cin >> inputChoice;
   
    switch (inputChoice) {
    case '1': {
        fstream file("wagon.txt");
        if (file.is_open()) {
            int wagon_number;
            while (file >> wagon_number) {
                if (wagon_number % 2 == 0) {
                    train1.push(wagon_number);
                }
                else {
                    train2.push(wagon_number);
                }
            }
            file.close();

            cout << "First train: ";
            train1.output();
            cout << "\nSecond train: ";
            train2.output();
        }
        else {
            cout << "Failed to open the file.\n";
        }
        break;

    }
    case '2': {
         int input_wagon;
         cout << "Enter wagon number (0 to finish): ";
        while (cin >> input_wagon && input_wagon != 0) {
        if (input_wagon % 2 == 0) {
            train1.push(input_wagon);
        }
        else {
            train2.push(input_wagon);
        }
        cout << "Enter wagon number (0 to finish): ";
        }

        cout << "First train: ";
        train1.output();
        cout << "\nSecond train: ";
        train2.output();
        break;
    }
    default:
        cout << "Invalid choice." << endl;
        return 1;
    }

    return 0;
}

