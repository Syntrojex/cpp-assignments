//#include<iostream>
//#include<string>
//#include<iomanip>
//#include<cctype>
//#include<fstream>
//
//using namespace std;
//
//bool emptySpace(string val)
//{
//	if (val.length() == 0)
//	{
//		return true;
//	}
//
//	for (int i = 0; i < val.length(); i++)
//	{
//		if (val[i] != ' ')
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//bool searching(string text, string word)
//{
//	if (word.length() > text.length())
//	{
//		return false;
//	}
//
//	for (int i = 0; i <= text.length() - word.length(); i++)
//	{
//		bool flag = true;
//		for (int j = 0; j < word.length(); j++)
//		{
//			if (text[i + j] != word[j])
//			{
//				flag = false;
//				break;
//			}
//		}
//		if (flag)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//int category(string word)
//{
//	if (searching(word, "Appetizer"))
//	{
//		return 1;
//	}
//	if (searching(word, "Main Course"))
//	{
//		return 2;
//	}
//	if (searching(word, "Dessert"))
//	{
//		return 3;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int convert(string num)
//{
//	int price = 0;
//	for (int i = 0; i < num.length(); i++)
//	{
//		if (num[i] >= '0' && num[i] <= '9')
//		{
//			price = price * 10 + (num[i] - '0');
//		}
//	}
//	return price;
//}
//
//
//void sorting(string** menu, int start, int end)
//{
//	for (int i = start; i < end; i++)
//	{
//		for (int j = start; j < end - (i - start); j++)
//		{
//			bool swap = false;
//
//			//Checking Restaurant Name
//			if (menu[j][4] > menu[j + 1][4])
//			{
//				swap = true;
//			}
//
//			//Checking Category
//			else if (menu[j][4] == menu[j + 1][4])
//			{
//				int categ1 = category(menu[j][0]);
//				int categ2 = category(menu[j + 1][0]);
//
//				if (categ1 > categ2)
//				{
//					swap = true;
//				}
//				//Checking Price
//				else if (categ1 == categ2)
//				{
//					int price1 = convert(menu[j][3]);
//					int price2 = convert(menu[j + 1][3]);
//					if (price1 > price2)
//					{
//						swap = true;
//					}
//				}
//			}
//			if (swap)
//			{
//				for (int a = 0; a < 8; a++)
//				{
//					string temp = menu[j][a];
//					menu[j][a] = menu[j + 1][a];
//					menu[j + 1][a] = temp;
//				}
//			}
//		}
//	}
//}
//
//string uppercase(string word)
//{
//	string result = "";
//	for (int i = 0; i < word.length(); i++)
//	{
//		result += toupper(word[i]);
//	}
//	return result;
//}
//
//void SearchCuisine(string** menu)
//{
//	string term;
//	cout << "Enter Cuisine to search: ";
//	cin >> term;
//
//	term = uppercase(term);
//	for (int a = 0; a < 7; a++)
//	{
//		cout << left;
//		cout << setw(25) << menu[0][a];
//	}
//	cout << endl;
//
//	bool flag = false;
//
//	for (int i = 1; i < 13; i++)
//	{
//		if (searching(uppercase(menu[i][1]), term))
//		{
//			for (int a = 0; a < 7; a++)
//			{
//				cout << left;
//				cout << setw(25) << menu[i][a];
//			}
//			flag = true;
//			cout << endl;
//		}
//	}
//	if (!flag)
//	{
//		cout << "ERROR: Cuisine Not Found!!" << endl;
//	}
//}
//
//int main()
//{
//	string store[12][7];
//	ifstream file("Q1_menu.txt");
//
//	if (!file)
//	{
//		cout << "Error Opening File" << endl;
//	}
//
//	string line;
//	int rows = 0;
//
//	while (getline(file, line) && rows < 12)
//	{
//		int columns = 0;
//		string word = "";
//
//		for (int i = 0; i < line.length(); i++)
//		{
//			if (line[i] == ',')
//			{
//				if (emptySpace(word))
//				{
//					store[rows][columns] = "Not Available!!";
//				}
//				else
//				{
//					store[rows][columns] = word;
//				}
//				columns++;
//				word = "";
//			}
//			else
//			{
//				word += line[i];
//			}
//		}
//		if (columns < 7)
//		{
//			if (emptySpace(word))
//			{
//				store[rows][columns] = "Not Available!!";
//			}
//			else
//			{
//				store[rows][columns] = word;
//			}
//		}
//
//		columns++;
//		while (columns < 7)
//		{
//			store[rows][columns] = "Not Available!!";
//		}
//		rows++;
//	}
//
//	file.close();
//
//
//	string** menu = new string * [rows + 1];
//	for (int i = 0; i < rows + 1; i++)
//	{
//		menu[i] = new string[8];
//	}
//
//	cout << "Original Data: " << endl;
//	cout << left;
//	for (int i = 0; i < rows; i++)
//	{
//		if (i == 1)
//		{
//			cout << endl;
//		}
//		for (int j = 0; j < 7; j++)
//		{
//			cout << setw(25) << store[i][j];
//		}
//		cout << endl;
//	}
//
//	menu[0][0] = "Category";
//	menu[0][1] = "Cuisine Type";
//	menu[0][2] = "Item Name";
//	menu[0][3] = "Price";
//	menu[0][4] = "Restaurant Name";
//	menu[0][5] = "Cook Name";
//	menu[0][6] = "Calories";
//	menu[0][7] = '\0';
//
//	int menuRow = 1;
//	bool copied[12] = { false };
//
//	//Mexican
//	int mexicStart = menuRow;
//	for (int i = 0; i < rows; i++)
//	{
//		if (!copied[i] && searching(store[i][1], "Mexican"))
//		{
//			for (int j = 0; j < 7; j++)
//			{
//				menu[menuRow][j] = store[i][j];
//			}
//			copied[i] = true;
//			menu[menuRow][7] = '\0';
//			menuRow++;
//		}
//	}
//	int mexicEnd = menuRow - 1;
//	if (mexicEnd > mexicStart)
//	{
//		sorting(menu, mexicStart, mexicEnd);
//	}
//
//	//American
//	int americStart = menuRow;
//	for (int i = 0; i < rows; i++)
//	{
//		if (!copied[i] && searching(store[i][1], "American"))
//		{
//			for (int j = 0; j < 7; j++)
//			{
//				menu[menuRow][j] = store[i][j];
//			}
//			copied[i] = true;
//			menu[menuRow][7] = '\0';
//			menuRow++;
//		}
//	}
//	int americEnd = menuRow - 1;
//	if (americEnd > americStart)
//	{
//		sorting(menu, americStart, americEnd);
//	}
//
//	//Fusion
//	int fusStart = menuRow;
//	for (int i = 0; i < rows; i++)
//	{
//		if (!copied[i] && !searching(store[i][1], "Experimental") && searching(store[i][1], "Fusion"))
//		{
//			for (int j = 0; j < 7; j++)
//			{
//				menu[menuRow][j] = store[i][j];
//			}
//			copied[i] = true;
//			menu[menuRow][7] = '\0';
//			menuRow++;
//		}
//	}
//	int fusEnd = menuRow - 1;
//	if (fusEnd > fusStart)
//	{
//		sorting(menu, fusStart, fusEnd);
//	}
//
//	//Fusion
//	int experStart = menuRow;
//	for (int i = 0; i < rows; i++)
//	{
//		if (!copied[i] && searching(store[i][1], "Experimental"))
//		{
//			for (int j = 0; j < 7; j++)
//			{
//				menu[menuRow][j] = store[i][j];
//			}
//			copied[i] = true;
//			menu[menuRow][7] = '\0';
//			menuRow++;
//		}
//	}
//	int experimentalend = menuRow - 1;
//	if (experimentalend > experStart)
//	{
//		sorting(menu, experStart, experimentalend);
//	}
//
//	cout << "\n\n\nSorted Menu: " << endl;
//	cout << left;
//	for (int i = 0; i <= rows; i++)
//	{
//		if (i == 1)
//		{
//			cout << endl;
//		}
//		for (int j = 0; j < 7; j++)
//		{
//			cout << setw(25) << menu[i][j];
//		}
//		cout << endl;
//	}
//
//	int a = 2;
//	cout << "\n\n" << endl;
//
//	SearchCuisine(menu);
//
//	ofstream fout("Output.txt");
//	fout << "Menu: \n" << endl;
//	fout << left;
//	for (int i = 0; i <= rows; i++)
//	{
//		if (i == 1)
//		{
//			fout << endl;
//		}
//		for (int j = 0; j < 7; j++)
//		{
//			fout << setw(25) << menu[i][j];
//		}
//		fout << endl;
//	}
//	fout.close();
//
//	for (int i = 0; i <= rows; i++)
//	{
//		delete[] menu[i];
//	}
//	delete[]menu;
//	menu = nullptr;A
//
//	return 0;
//}