#include "../App1_university/Vector3D.h"

int main()
{
    Vector3D vector1(1, 2, 3);
    Vector3D vector2(-2, 0, 1);

    int choice;
    do {
        cout << "Choose an option:" << endl;
        cout << "1. Add vectors" << endl;
        cout << "2. Subtract vectors" << endl;
        cout << "3. Calculate dot product" << endl;
        cout << "4. Calculate vector length" << endl;
        cout << "5. Calculate cosine angle between vectors" << endl;
        cout << "6. Exit" << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Adding vectors:" << endl;
            vector1.add(vector2).display();
            cout << endl;
            break;
        case 2:
            cout << "Subtracting vectors:" << endl;
            vector1.subtract(vector2).display();
            cout << endl;
            break;
        case 3:
            cout << "Calculating dot product:" << endl;
            cout << vector1.dotProduct(vector2) << endl;
            break;
        case 4:
            cout << "Calculating vector length:" << endl;
            cout << vector1.length() << endl;
            break;
        case 5:
            cout << "Calculating cosine angle between vectors:" << endl;
            cout << vector1.cosineAngle(vector2) << endl;
            break;
        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }

    } while (choice != 6);

	return 0;
}
