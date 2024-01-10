#include "Rectangle.h"

int main()
{
    Rectangle rect1(0, 0, 5, 3);
    Rectangle rect2(2, 1, 4, 2);

    int choice;

    do {
        cout << "\nMenu:\n1. Move rectangle\n2. Resize rectangle\n3. Minimum Bounding Rectangle\n"
            "4. Intersection Rectangle\n5. Display rectangles\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1: 
        {
            double dx, dy;
            cout << "Enter displacement in x and y: ";
            cin >> dx >> dy;
            rect1.move(dx, dy);
            rect2.move(dx, dy);
            break;
        }
        case 2: 
        {
            double newWidth, newHeight;
            cout << "Enter new width and height: ";
            cin >> newWidth >> newHeight;
            rect1.resize(newWidth, newHeight);
            rect2.resize(newWidth, newHeight);
            break;
        }
        case 3: 
        {
            Rectangle boundingRect = Rectangle::minimumBoundingRectangle(rect1, rect2);
            boundingRect.display();
            break;
        }
        case 4: 
        {
            Rectangle intersectRect = Rectangle::intersection(rect1, rect2);
            intersectRect.display();
            break;
        }
        case 5:
            cout << "Rectangle 1:\n";
            rect1.display();
            cout << "Rectangle 2:\n";
            rect2.display();
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

	return 0;
}
