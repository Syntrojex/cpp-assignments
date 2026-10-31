#include<iostream>
using namespace std;
int main()
{
	int rows;

	// input validity check
	do
	{
		cout << "Enter the Number of Rows: ";
		cin >> rows;
		if (rows < 0)
		{
			cout << "Error: Enter Positive number!!" << endl;
		}
	} while (rows < 0);

	for (int i = rows ; i >= 1; i--)
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

	for (int i = 2; i <= rows; i++)  // i started from 2 because one star has already printed by previous loop
	{
		for (int space = 1; space <= rows - i; space++)  
		{
			cout << " ";
		}
		for (int j = 1; j <= i; j++)   
		{
			cout << "*" << " ";
		}
		cout << endl;
	}


	cout << endl;
	system("pause");
	return 0;
}