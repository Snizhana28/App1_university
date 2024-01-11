#include <iostream>
using namespace std;

class Matrix {
private:
    int** matrix;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        matrix = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = 0;
            }
        }
    }
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    void printMatrix() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void resizeMatrix(int newRows, int newCols) {
        int** newMatrix = new int* [newRows];
        for (int i = 0; i < newRows; ++i) {
            newMatrix[i] = new int[newCols];
            for (int j = 0; j < newCols; ++j) {
                newMatrix[i][j] = 0;
            }
        }
        for (int i = 0; i < std::min(rows, newRows); ++i) {
            for (int j = 0; j < std::min(cols, newCols); ++j) {
                newMatrix[i][j] = matrix[i][j];
            }
        }
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;

        matrix = newMatrix;
        rows = newRows;
        cols = newCols;
    }

    int getElement(int row, int col) const {
        return matrix[row][col];
    }

    void setElement(int row, int col, int value) {
        matrix[row][col] = value;
    }
};