#include<iostream>
using namespace std;
int main()
{
	int num;
	cout << "Enter a number: ";
	cin >> num;

	int count = 0;
	int n = 2;      // because prime numbers start from 2
	
	if (num < 0)
	{
		cout << "Error: Enter a Positive Number!!" << endl;
		return 0;
	}

	else
	{
		cout << "First " << num << " prime numbers are: " << endl;
			while (count < num)
			{
				int a = 1;          // assumed prime   
				for (int i = 2; i <= n - 1; i++)
				{
					if (n % i == 0)
					{
						a = 0;
						// if a factor is found then a will be store 0 
						// but if no factor is found a will store 1 means prime
					}

				}
				if (a == 1)
				{
					cout << n << " ";
					count++;
				}
				n++;
			}
	}

	cout << endl;
	system("pause");
	return 0;
}