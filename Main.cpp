#include "child/Circle.h"
#include "child/Square.h"
#include "child/Rectangle.h"

int main()
{
    Circle circle(0, 0, 5);
    Square square(2, 2, 4);
    Rectangle rectangle(-1, -1, 6, 3);

    int choice;
    do {
        cout << "Choose an option:" << endl;
        cout << "1. Display figures" << endl;
        cout << "2. Move figures" << endl;
        cout << "3. Resize figures" << endl;
        cout << "4. Exit" << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Displaying figures:" << endl;
            circle.display();
            square.display();
            rectangle.display();
            break;
        case 2:
            double dx, dy;
            cout << "Enter the movement values (dx dy): ";
            cin >> dx >> dy;
            circle.move(dx, dy);
            square.move(dx, dy);
            rectangle.move(dx, dy);
            break;
        case 3:
            double scale;
            cout << "Enter the scaling factor: ";
            cin >> scale;
            circle.resize(scale);
            square.resize(scale);
            rectangle.resize(scale);
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }

    } while (choice != 4);

	return 0;
}
