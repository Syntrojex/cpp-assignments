#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int num;

	do
	{
		cout << "Enter a Number: ";
		cin >> num;
		if (num < 0)
		{
			cout << "Error: Enter a positive number!!" << endl;
		}
		else if (num == 0)
		{
			cout << "Error: Number can't be 0!!" << endl;
		}
	} while (num < 0 || num == 0);

	for (int i = 1; i < num; i++)
	{
		int a = 1;
		for (int space = 1; space <= num - i; space++)
		{
			cout << "  ";
		}
		for (int j = 1; j <= i; j++)
		{
			int factorial1 = 1;
			int factorial2 = 1;
			int factorial3 = 1;

			//loop to find n! of combination formula
			for (int x = 1; x <= i - 1; x++)
			{
				factorial1 *= x;
			}

			// loop to find r! of combination formula
			for (int y = 1; y <= j - 1; y++)
			{
				factorial2 *= y;
			}

			//loop to find (n-r)! of combination formula
			for (int z = 1; z <= (i - j); z++)
			{
				factorial3 *= z;
			}
			// using combination formula n!/(n-r)!r!
			a = factorial1 / (factorial2 * factorial3);
			cout << setw(3) << a << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}