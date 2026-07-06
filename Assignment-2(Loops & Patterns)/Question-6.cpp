#include<iostream>
using namespace std;
int main()
{
	char input;  // Variable to control loop
	int id = 1;  // Customer ID
	int order = 1;

	// Do while loop used so that code runs at least one time
	do
	{
		int choice;
		int cups;
		int extras = 0;
		int basePrice;
		int sugar;
		int cream;

		// MENU display
		cout << "==================================" << endl;
		cout << "        WELCOME TO FAST HUB       " << endl;
		cout << "==================================" << endl;
		cout << "Please choose your coffee type:" << endl;
		cout << " 1. Espresso    - Rs. 230" << endl;
		cout << " 2. Cappuccino  - Rs. 250" << endl;
		cout << " 3. Latte       - Rs. 150" << endl;
		cout << "----------------------------------" << endl;
		cout << "Enter your choice (1-3): ";
		cin >> choice;

		// Checking validity of Input
		if (choice < 1 || choice > 3)
		{
			cout << "Enter valid number!!" << endl;
			return 0;
		}

		else
		{
			if (choice == 1)
			{
				cout << "Enter number of cups: ";
				cin >> cups;

				if (cups <= 0)
				{
					cout << "You must order at least 1 cup!!" << endl;
					return 0;
				}
				else
				{
					basePrice = cups * 230;
				}

				cout << "Do you want extra sugar ? (1 = Yes, 0 = No): ";
				cin >> sugar;
				cout << "Do you want extra cream ? (1 = Yes, 0 = No): ";
				cin >> cream;

				// Calculations of Extras
				if (sugar == 1 && cream == 1)
				{
					extras = 30 + 50;
				}
				else if (sugar == 1)
				{
					extras = 30;
				}
				else if (cream == 1)
				{
					extras = 50;
				}

				// Calculations
				float bill = basePrice + extras;
				float tax = 0.20 * bill;
				float totalbill = bill + tax;

				// Output Display
				cout << "\n============================" << endl;
				cout << "Customer ID:    " << id << endl;
				cout << "Order Number:   " << order << endl;
				cout << "----------------------------------" << endl;
				cout << "          ORDER DETAILS           " << endl;
				cout << "You ordered ==> Espresso" << endl;
				cout << "Cups:   " << cups << endl;
				cout << "Bill:     " << bill << endl;
				cout << "Service Tax:    " << tax << endl;
				cout << "----------------------------------" << endl;
				cout << "TOTAL BILL:     " << totalbill << endl;
				cout << "==================================" << endl;

			}

			else if (choice == 2)
			{
				cout << "Enter number of cups: ";
				cin >> cups;

				if (cups <= 0)
				{
					cout << "You must order at least 1 cup!!" << endl;
					return 0;
				}

				else
				{
					basePrice = cups * 250;
				}

				cout << "Do you want extra sugar ? (1 = Yes, 0 = No): ";
				cin >> sugar;
				cout << "Do you want extra cream ? (1 = Yes, 0 = No): ";
				cin >> cream;

				// Calculations of Extras
				if (sugar == 1 && cream == 1)
				{
					extras = 30 + 50;
				}
				else if (sugar == 1)
				{
					extras = 30;
				}
				else if (cream == 1)
				{
					extras = 50;
				}

				//Calculations
				float bill = basePrice + extras;
				float tax = 0.20 * bill;
				float totalbill = bill + tax;

				//Output Display
				cout << "\n============================" << endl;
				cout << "Customer ID:    " << id << endl;
				cout << "Order Number:   " << order << endl;
				cout << "----------------------------------" << endl;
				cout << "          ORDER DETAILS           " << endl;
				cout << "You ordered ==> Cappuccino" << endl;
				cout << "Cups:   " << cups << endl;
				cout << "Bill:     " << bill << endl;
				cout << "Service Tax:    " << tax << endl;
				cout << "----------------------------------" << endl;
				cout << "TOTAL BILL:     " << totalbill << endl;
				cout << "==================================" << endl;
			}

			else if (choice == 3)
			{
				cout << "Enter number of cups: ";
				cin >> cups;

				if (cups <= 0)
				{
					cout << "You must order at least 1 cup!!" << endl;
					return 0;
				}
				else
				{
					basePrice = cups * 150;
				}

				cout << "Do you want extra sugar ? (1 = Yes, 0 = No): ";
				cin >> sugar;
				cout << "Do you want extra cream ? (1 = Yes, 0 = No): ";
				cin >> cream;

				// Calculations of Extras
				if (sugar == 1 && cream == 1)
				{
					extras = 30 + 50;
				}
				else if (sugar == 1)
				{
					extras = 30;
				}
				else if (cream == 1)
				{
					extras = 50;
				}

				// Output Display
				float bill = basePrice + extras;
				float tax = 0.20 * bill;
				float totalbill = bill + tax;

				cout << "\n============================" << endl;
				cout << "Customer ID:    " << id << endl;
				cout << "Order Number:   " << order << endl;
				cout << "----------------------------------" << endl;
				cout << "          ORDER DETAILS           " << endl;
				cout << "You ordered ==> Latte" << endl;
				cout << "Cups:   " << cups << endl;
				cout << "Bill:     " << bill << endl;
				cout << "Service Tax:    " << tax << endl;
				cout << "----------------------------------" << endl;
				cout << "TOTAL BILL:     " << totalbill << endl;
				cout << "==================================" << endl;
			}
		}

		cout << "Do you want to order another coffee ? (Enter 'y' for YES and 'n' for NO): " << endl;
		cin >> input;

		if (input == 'y' || input == 'Y')
		{
			id++;
			order++;
		}

		else if (input == 'n' || input == 'N')
		{
			cout << "----------Thank you----------" << endl;
		}

	} while (input != 'n' && input != 'N');

	cout << endl;
	system("pause");
	return 0;
}