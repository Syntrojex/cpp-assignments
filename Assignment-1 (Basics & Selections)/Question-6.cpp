#include<iostream>
using namespace std;
int main()
{
	int choice;
	int cups;
	int extras;
	cout << "----------Welcome to \"Caffeine Hub\" ----------" << endl;
	cout << "Which type of Coffee would you like to order?" << endl;
	cout << "* Espresso = Rs. 150 (Enter--> 1)" << endl;
	cout << "* Cappuccino = Rs. 180 (Enter--> 2)" << endl;
	cout << "* Latte = Rs. 200 (Enter--> 3)" << endl;
	cout << "\nEnter your choice: ";
	cin >> choice;         // asking user to enter type of coffee

	cout << "Enter the number of cups: ";
	cin >> cups;           // asking user to enter number of cups

	// handling invalid input

	if (cups <= 0)
	{
		cout << "Invalid order! You must order at least 1 cup" << endl;
	}
	else
	{
		cout << "\nDo you want extra sugar (Rs. 20) or whipped cream (Rs. 30)? " << endl;
		cout << "Enter 1 for only sugar " << endl;
		cout << "Enter 2 for only cream " << endl;
		cout << "Enter 3 for both " << endl;
		cout << "Enter 4 for none " << endl;

		cin >> extras;

		int bill = 0;

		if (choice == 1)
		{
			bill = (150 * cups);
		}
		else if (choice == 2)
		{
			bill = (180 * cups);
		}
		else if (choice == 3)
		{
			bill = (200 * cups);
		}

		if (extras == 1)
		{
			bill = bill + 20;
		}
		else if (extras == 2)
		{
			bill = bill + 30;
		}
		else if (extras == 3)
		{
			bill = bill + 20 + 30;
		}

		float tax = bill * 0.1;    // tax 10%
		float total_bill = bill + tax;

		// output to user

		cout << "----------Order details----------" << endl;
		cout << "Base Bill: Rs." << bill << endl;
		cout << "Tax (10%): Rs." << tax << endl;
		cout << "Total Bill: Rs." << total_bill << endl;
		cout << "\n----------Thanks for coming! Enjoy your Coffee!----------" << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
