#include "../App1_university/Matrix.h"

int main() {

    int rows, cols;
    cout << "Enter the number of rows of the matrix: ";
    cin >> rows;
    cout << "Enter the number of columns in the matrix: ";
    cin >> cols;

    Matrix myMatrix(rows, cols);

    int choice;
    do {
        cout << "1. Print the matrix \n2. Resize the matri \n3. Print the matrix element"
            "\n4.Change the matrix element \n0.Exit \nYour choice : ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nMatrix:\n";
            myMatrix.printMatrix();
            break;

        case 2: {
            int newRows, newCols;
            cout << "\nEnter the new number of matrix rows: ";
            cin >> newRows;
            cout << "Enter the new number of matrix columns: ";
            cin >> newCols;

            myMatrix.resizeMatrix(newRows, newCols);
            cout << "Matrix size changed.\n";
            break;
        }

        case 3: {
            int row, col;
            cout << "\nEnter the line number: ";
            cin >> row;
            cout << "Enter the column number: ";
            cin >> col;

            cout << "Matrix element: " << myMatrix.getElement(row, col) << endl;
            break;
        }

        case 4: {
            int row, col, value;
            cout << "\nEnter the line number: ";
            cin >> row;
            cout << "Enter the column number: ";
            cin >> col;
            cout << "Enter a new value: ";
            cin >> value;

            myMatrix.setElement(row, col, value);
            cout << "The value of a matrix element has been changed.\n";
            break;
        }

        case 0:
            cout << "Exit.\n";
            break;

        default:
            cout << "Wrong choice. Please try again.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}