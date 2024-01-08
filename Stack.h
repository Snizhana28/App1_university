#include "library.h"
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
    bool isEmpty() { return (top_elem == -1) ? true : false; }
    bool isFull() { return (top_elem == size) ? true : false; }
};
