#include<iostream>
#include<iomanip>      // So that precision can be set to 2 decimal places
using namespace std;
int main()
{
	int courses;
	float grade;    // float is chosen because grade points may have decimals
	int credits;
	float numerator = 0;
	float denominator = 0;
	float temp;
	float sgpa;

	//  input validity check
	do
	{
		cout << "Enter number of courses: ";
		cin >> courses;
		if (courses < 0)
		{
			cout << "Error: Number of courses must be positive!!" << endl;
		}

		else if (courses == 0)
		{
			cout << "Error: Number of courses cannot be zero!!" << endl;
		}

	} while (courses < 0 || courses == 0);

	for (int i = 1; i <= courses; i++)
	{
		cout << "Course: " << i << endl;
		do
		{
			cout << "Credit hours for course " << i << ": ";
			cin >> credits;
			if (credits < 1 || credits>3)
			{
				cout << "Credit hours must lie between 1 and 3!!" << endl;
			}

		} while (credits < 1 || credits>3);

		do
		{
			cout << "Grade points for course " << i << ": ";
			cin >> grade;
			if (grade < 0 || grade>4)
			{
				cout << "Grade points must lie between 0 and 4!!" << endl;
			}

		} while (grade < 0 || grade>4);
		cout << endl;

		temp = credits * grade;
		numerator += temp;
		denominator += credits;
	}

	sgpa = numerator / denominator;

	cout << "----------------------------------------" << endl;
	cout << "             GRADE REPORT               " << endl;
	cout << "----------------------------------------" << endl;
	cout << fixed << setprecision(2); // because gpa has 2 decimal places
	cout << "SGPA: " << sgpa << endl;

	cout << endl;
	system("pause");
	return 0;
}