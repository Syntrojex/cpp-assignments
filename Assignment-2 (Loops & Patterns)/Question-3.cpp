#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int num;
	int k;

	do
	{
		cout << "Enter a perfect square: ";
		cin >> num;

		if (num <= 0)
		{
			cout << "Error: Enter a positive value!!" << endl;
			continue;
		}

		k = 1;
		while (k * k < num)
		{
			k++;
		}

		if (k * k == num)
		{
			break;
		}
		else
		{
			cout << "Error: Enter a perfect square!!" << endl;
		}

	} while (true);

	int rows = 1;
	int columns = k+1;

	while (rows <= k)
	{
		cout << rows << "  ";
		rows++;
	}
	cout << endl;

	while (columns <= (2 * k) - 2)  
	{
		cout << setw(2 * k + 3) << columns << endl;
		columns++;
	}

	for (int m = (3 * k) - 2; m >= (2 * k)-1; m--)   
	{
		cout << m << " ";
	}

	cout << endl;
	system("pause");
	return 0;
}
