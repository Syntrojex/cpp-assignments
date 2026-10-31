#include<iostream>
using namespace std;
int main()
{
	int rows;

	// do while loop used for input validity check 
	do
	{
		cout << "Enter the number of Rows: ";
		cin >> rows;
		if (rows < 0)
		{
			cout << "Error: Enter positive number!!" << endl;
		}
	} while (rows < 0);

	for (int i = 1; i <= rows; i++)  // loop to control rows
	{
		for (int space = 1; space <= rows - i; space++)  // loop to control spaces 
		{
			cout << " ";
		}
		for (int j = 1; j <= i; j++)   // loop to print stars
		{
			cout << "*" << " ";
		}
		cout << endl;
	}
	for (int i = rows - 1; i >= 1; i--)
	{
		for (int space = 1; space <= rows - i; space++)
		{
			cout << " ";
		}
		for (int j = 1; j <= i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}