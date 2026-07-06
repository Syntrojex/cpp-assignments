#include<iostream>
#include<iomanip>    // I have added iomanip just to format my table
using namespace std;
int main()
{
	cout << "-----------------------------------------\n";
	cout << "     Multiplication Table Generator\n";
	cout << "-----------------------------------------\n\n";

	int number;
	cout << "Enter the number: ";
	cin >> number;
	

	// Checking that either number is greater than 0 or equal to 0
	if (number < 0)
	{
		cout << "Error: Number must be greater than 0!" << endl;
		return 0;
	}

	else if (number == 0)
	{
		cout << "Error: Table of 0 does not exist!" << endl;
		return 0;
	}
	
	else
	{
		// Asking user How far the table must go
		int end_point;
		cout << "Enter the number how far the Table must go: ";
		cin >> end_point;

		// Checking ending limit
		if (end_point < 0)
		{
			cout << "Ending must be greater than 0!!" << endl;
			return 0;
		}

		else if (end_point == 0)
		{
			cout << "Ending point cannot be 0!!" << endl;
			return 0;
		}

		else
		{
			cout << "------------------------------------------------" << endl;
			cout << "Multiplication Table of " << number << " from 1 to " << end_point << " is: " << endl;

			// Loop for Table printing and calculations
			for (int i = 1; i <= end_point; i++)
			{
				cout << number << " x " << setw(3) << i << " = " << setw(5) << number * i << endl;
			}
		}
	}

	cout << endl;
	system("pause");
	return 0;
}