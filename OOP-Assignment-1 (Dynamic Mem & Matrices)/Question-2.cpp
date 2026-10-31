#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string** cart = nullptr;
int* attrCount = nullptr;
int items = 0;

void addItem()
{
	string** newCart = new string * [items + 1];
	int* newAttrCount = new int[items + 1];

	for (int i = 0; i < items; i++)
	{
		*(newCart + i) = *(cart + i);
		*(newAttrCount + i) = *(attrCount + i);
	}

	int id;
	string name;

	cout << "Enter Item ID: ";
	cin >> id;
	cout << "Enter Item Name: ";
	cin >> name;

	newCart[items] = new string[2];   // ID or Name rkha
	newCart[items][0] = to_string(id);
	newCart[items][1] = name;

	newAttrCount[items] = 2;

	delete[] cart;
	delete[] attrCount;

	cart = newCart;
	attrCount = newAttrCount;
	items++;

	cout << "Item added successfully!\n";
}

void addAttribute()
{
	int id;
	cout << "Enter Item ID: ";
	cin >> id;

	for (int i = 0; i < items; i++)
	{
		if (stoi(cart[i][0]) == id)
		{
			string attrName, attrValue;
			cout << "Enter Attribute Name: ";
			cin >> attrName;
			cout << "Enter Attribute Value: ";
			cin >> attrValue;

			string* newRow = new string[*(attrCount + i) + 2];

			for (int j = 0; j < *(attrCount + i); j++)
			{
				newRow[j] = *(*(cart + i) + j);
			}

			newRow[*(attrCount + i)] = attrName;
			newRow[*(attrCount + i) + 1] = attrValue;

			delete[] * (cart + i);
			*(cart + i) = newRow;
			*(attrCount + i) += 2;

			cout << "Attribute added successfully!\n";
			return;
		}
	}
	cout << "Item not found!\n";
}

void getItemInfo()
{
	int id;
	cout << "Enter Item ID: ";
	cin >> id;

	for (int i = 0; i < items; i++)
	{
		if (stoi(cart[i][0]) == id)
		{
			cout << "Item ID: " << cart[i][0] << endl;
			cout << "Name: " << cart[i][1] << endl;

			for (int j = 2; j < *(attrCount + i); j += 2)
			{
				cout << *(*(cart + i) + j) << ": " << cart[i][j + 1] << endl;
			}

			return;
		}
	}
	cout << "Item not found!\n";
}

void sortCart()
{
	string attr;
	cout << "Enter Attribute to Sort By: ";
	cin >> attr;

	for (int i = 0; i < items - 1; i++)
	{
		for (int j = i + 1; j < items; j++)
		{
			double val1 = 0, val2 = 0;

			for (int k = 2; k < *(attrCount + i); k += 2)
			{
				if (cart[i][k] == attr)
				{
					val1 = stod(cart[i][k + 1]);
				}
			}

			for (int k = 2; k < *(attrCount + j); k += 2)
			{
				if (cart[j][k] == attr)
				{
					val2 = stod(cart[j][k + 1]);
				}
			}

			if (val1 > val2)
			{
				swap(cart[i], cart[j]);
				swap(*(attrCount + i), *(attrCount + j));
			}
		}
	}

	cout << "Cart sorted successfully!\n";
	cout << "Items in Cart:\n";

	for (int i = 0; i < items; i++)
	{
		cout << cart[i][0] << " - " << cart[i][1] << " - ";
		for (int j = 2; j < *(attrCount + i); j += 2)
		{
			if (*(*(cart + i) + j) == attr)
			{
				cout << cart[i][j + 1];
			}
		}
		cout << endl;
	}
}

void totalValue()
{
	string attr;
	cout << "Enter Price Attribute Name: ";
	cin >> attr;

	double total = 0;

	for (int i = 0; i < items; i++)
	{
		for (int j = 2; j < attrCount[i]; j += 2)
		{
			if (*(*(cart + i) + j) == attr)
			{
				total += stod(cart[i][j + 1]);
			}
		}
	}

	cout << "Total Cart Value: " << total << endl;
}

void averageValue()
{
	string attr;
	cout << "Enter Price Attribute Name: ";
	cin >> attr;

	double total = 0;
	int count = 0;

	for (int i = 0; i < items; i++)
		for (int j = 2; j < attrCount[i]; j += 2)
			if (cart[i][j] == attr)
			{
				total += stod(cart[i][j + 1]);
				count++;
			}

	if (count == 0)
	{
		cout << "Average Cart Value: 0\n";
	}
	else
	{
		cout << "Average Cart Value: " << fixed << setprecision(2) << total / count << endl;
	}
}

void filterItems()
{
	string attr, value;
	cout << "Enter Attribute Name: ";
	cin >> attr;
	cout << "Enter Attribute Value: ";
	cin >> value;

	cout << "Filtered Items:\n";

	for (int i = 0; i < items; i++)
	{
		for (int j = 2; j < *(attrCount + i); j += 2)
		{
			if (*(*(cart + i) + j) == attr && cart[i][j + 1] == value)
			{
				cout << cart[i][0] << " - " << cart[i][1] << endl;
			}
		}
	}
}

void removeAttribute()
{
	int id;
	string attr;
	cout << "Enter Item ID: ";
	cin >> id;
	cout << "Enter Attribute Name to Remove: ";
	cin >> attr;

	for (int i = 0; i < items; i++)
	{
		if (stoi(cart[i][0]) == id)
		{
			for (int j = 2; j < *(attrCount + i); j += 2)
			{
				if (cart[i][j] == attr)
				{
					string* newRow = new string[*(attrCount + i) - 2];
					int index = 0;

					for (int k = 0; k < *(attrCount + i); k++)
					{
						if (k != j && k != j + 1)
						{
							newRow[index++] = cart[i][k];
						}
					}

					delete[] * (cart + i);
					*(cart + i) = newRow;
					*(attrCount + i) -= 2;

					cout << "Attribute removed successfully!\n";
					return;
				}
			}
		}
	}
}

void removeItem()
{
	int id;
	cout << "Enter Item ID to Remove: ";
	cin >> id;

	for (int i = 0; i < items; i++)
	{
		if (stoi(cart[i][0]) == id)
		{
			delete[] * (cart + i);

			for (int j = i; j < items - 1; j++)
			{
				cart[j] = cart[j + 1];
				*(attrCount + j) = attrCount[j + 1];
			}

			items--;
			cout << "Item removed successfully!\n";
			return;
		}
	}
}

void clearCart()
{
	for (int i = 0; i < items; i++)
	{
		delete[] * (cart + i);
	}

	delete[] cart;
	delete[] attrCount;

	cart = nullptr;
	attrCount = nullptr;
	items = 0;

	cout << "Cart cleared successfully!\n";
}

int main()
{
	int choice;

	cout << "Program Start:\n";

	do
	{
		cout << "\n===== SHOPPING CART MENU =====\n";
		cout << "1. Add Item\n";
		cout << "2. Remove Item\n";
		cout << "3. Add Attribute\n";
		cout << "4. Remove Attribute\n";
		cout << "5. Get Item Info\n";
		cout << "6. Sort Cart By Attribute\n";
		cout << "7. Total Cart Value\n";
		cout << "8. Average Cart Value\n";
		cout << "9. Filter By Attribute\n";
		cout << "10. Clear Cart\n";
		cout << "0. Exit\n" << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			addItem();
			break;
		case 2:
			removeItem();
			break;
		case 3:
			addAttribute();
			break;
		case 4:
			removeAttribute();
			break;
		case 5:
			getItemInfo();
			break;
		case 6:
			sortCart();
			break;
		case 7:
			totalValue();
			break;
		case 8:
			averageValue();
			break;
		case 9:
			filterItems();
			break;
		case 10:
			clearCart();
			break;
		case 0:
			cout << "Thank you for using Shopping Cart System!\n";
			break;
		default:
			cout << "Invalid choice!\n";
			break;
		}

	} while (choice != 0);

	cout << "\n\n" << endl;
	system("pause");
	return 0;
}