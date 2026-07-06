#include<iostream>
using namespace std;
int main()
{
	int choice;

	cout << "What do you want to calculate?" << endl;
	cout << "Area and perimeter of Square (Press--> 1)" << endl;
	cout << "Area and perimeter of Rectangle (Press--> 2)" << endl;
	cout << "Area and perimeter of Circle (Press--> 3)" << endl;
	cout << "Perimeter of Triangle and Triangle type (Press-- 4)" << endl;
	cout << "\nEnter your choice: ";
	cin >> choice;

	// for square

	if (choice == 1)
	{
		int side;
		cout << "\nEnter the side of Square: ";
		cin >> side;

		int area_sq = side * side;
		int perimeter_sq = 4 * side;
		cout << "Area: " << area_sq << endl;
		cout << "Perimeter: " << perimeter_sq << endl;
	}

	// for rectangle

	else if (choice == 2)
	{
		int length;
		int width;
		cout << "Enter the length of rectangle: ";
		cin >> length;
		cout << "Enter the width of rectangle: ";
		cin >> width;

		int area_rect = length * width;
		int perimeter_rect = 2 * (length + width);
		cout << "Area: " << area_rect << endl;
		cout << "Perimeter: " << perimeter_rect << endl;

		if (length == width)
		{
			cout << "The given rectangle is also a Square" << endl;
		}
		else
		{
			cout << "The given rectangle is not a Square" << endl;
		}
	}

	// for circle

	else if (choice == 3)
	{
		float radius;
		const float pi = 3.14;
		cout << "Enter the radius of circle: ";
		cin >> radius;
		float area_circle = pi * radius * radius;
		float perimeter_circle = 2 * pi * radius;

		cout << "Area: " << area_circle << endl;
		cout << "Perimeter: " << perimeter_circle << endl;
	}

	// for triangle

	else if (choice == 4)
	{
		int a, b, c;
		cout << "Enter sides of Triangle: ";
		cin >> a;
		cin >> b;
		cin >> c;

		/* checking validity of triangle means that sum any two sides must be greater than the third one
		because a valid triangle has perimeter and area */

		if (a + b > c && b + c > a && a + c > b)
		{
			int perimeter_triangle = a + b + c;
			cout << "Perimeter: " << perimeter_triangle << endl;

			if (a == b && b == c)
			{
				cout << "Equilateral Triangle" << endl;
			}

			else if (a == b || b == c || a == c)
			{
				cout << "Isosceles Triangle" << endl;
			}

			else
			{
				cout << "Scalene Triangle" << endl;
			}
		}
		else
		{
			cout << "Not a valid Triangle!!" << endl;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}
