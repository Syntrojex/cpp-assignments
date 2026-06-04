#include<iostream>
using namespace std;
int main()
{
	int num;
	cout << "Enter a 8 digit number: ";
	cin >> num;

	if (num < 10000000 || num > 99999999)      // checking if number is 8 digit or not
	{
		cout << "Invalid Input! Please enter a 8 digit positive number!" << endl;
	}
	else
	{
		int d1, d2, d3, d4, d5, d6, d7, d8;       // for every digit

		// i divided to remove all first digits and % give us the last digit

		d1 = (num / 10000000) % 10;
		d2 = (num / 1000000) % 10;
		d3 = (num / 100000) % 10;
		d4 = (num / 10000) % 10;
		d5 = (num / 1000) % 10;
		d6 = (num / 100) % 10;
		d7 = (num / 10) % 10;
		d8 = num % 10;

		int rev = d8 * 10000000 + d7 * 1000000 + d6 * 100000 + d5 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1; // so that digits can be placed on their place

		cout << "Reversed number is: " << rev << endl;
		if (num == rev)
		{
			cout << "Number is Palindrome" << endl;
		}
		else
		{
			cout << "Not Palindrome" << endl;
		}

		int sum = d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8;
		cout << "Sum of digits is: " << sum << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}
