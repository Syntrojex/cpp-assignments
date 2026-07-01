//#include<iostream>
//using namespace std;
//
//class MyString {
//private:
//	char* str;
//	int length;
//
//	int stringLength(const char* str)
//	{
//		int len = 0;
//		while (*(str + len) != '\0')
//		{
//			len++;
//		}
//		return len;
//	}
//
//public:
//	int countWords() const
//	{
//		int count = 0;
//		bool inWord = false;
//
//		for (int i = 0; str[i] != '\0'; i++)
//		{
//			if (str[i] != ' ')
//			{
//				if (!inWord)
//				{
//					count++;
//					inWord = true;
//				}
//			}
//			else
//			{
//				inWord = false;
//			}
//		}
//
//		return count;
//	}
//
//	MyString()
//	{
//		str = new char[1];
//		str[0] = '\0';
//		length = 0;
//	}
//
//	MyString(const char* input)
//	{
//		if (input == nullptr)
//		{
//			str = new char[1];
//			str[0] = '\0';
//			length = 0;
//		}
//
//		else
//		{
//			length = stringLength(input);
//
//			str = new char[length + 1];
//
//			for (int i = 0; i <= length; i++)
//			{
//				*(str + i) = *(input + i);
//			}
//		}
//	}
//
//	MyString(const MyString& obj)
//	{
//		length = obj.length;
//
//		str = new char[length + 1];
//
//		for (int i = 0; i <= length; i++)
//		{
//			*(str + i) = *(obj.str + i);
//		}
//	}
//
//	MyString& operator=(const MyString& obj)
//	{
//		if (this == &obj)
//		{
//			return *this;
//		}
//
//		delete[] str;
//
//		length = obj.length;
//
//		str = new char[length + 1];
//
//		for (int i = 0; i <= length; i++)
//		{
//			str[i] = obj.str[i];
//		}
//
//		return *this;
//	}
//
//	void toUpperCase()
//	{
//		for (int i = 0; str[i] != '\0'; i++)
//		{
//			if (str[i] >= 'a' && str[i] <= 'z')
//			{
//				str[i] = str[i] - 32;
//			}
//		}
//	}
//
//	void toLowerCase()
//	{
//		for (int i = 0; str[i] != '\0'; i++)
//		{
//			if (str[i] >= 'A' && str[i] <= 'Z')
//			{
//				str[i] = str[i] + 32;
//			}
//		}
//	}
//
//	void toSentenceCase()
//	{
//		if (str[0] >= 'a' && str[0] <= 'z')
//		{
//			str[0] = str[0] - 32;
//		}
//
//		for (int i = 1; str[i] != '\0'; i++)
//		{
//			if (str[i] >= 'A' && str[i] <= 'Z')
//			{
//				str[i] = str[i] + 32;
//			}
//		}
//	}
//
//	MyString reverse() const
//	{
//		MyString temp;
//
//		temp.length = length;
//		temp.str = new char[length + 1];
//
//		int k = 0;
//
//		for (int i = length - 1; i >= 0; i--)
//		{
//			temp.str[k++] = str[i];
//		}
//
//		temp.str[length] = '\0';
//
//		return temp;
//	}
//
//	void display() const
//	{
//		cout << "String is: ";
//
//		for (int i = 0; i < length; i++)
//		{
//			cout << str[i];
//		}
//
//		cout << endl;
//	}
//
//	MyString operator+(const MyString& obj)
//	{
//		MyString temp;
//
//		temp.length = length + obj.length;
//		temp.str = new char[temp.length + 1];
//
//		int i = 0;
//
//		for (; i < length; i++)
//		{
//			temp.str[i] = str[i];
//		}
//
//		for (int j = 0; j <= obj.length; j++)
//		{
//			temp.str[i + j] = obj.str[j];
//		}
//
//		return temp;
//	}
//
//	MyString& operator+=(const MyString& obj)
//	{
//		char* newStr = new char[length + obj.length + 1];
//
//		int i = 0;
//
//		for (; i < length; i++)
//		{
//			newStr[i] = str[i];
//		}
//
//		for (int j = 0; j <= obj.length; j++)
//		{
//			newStr[i + j] = obj.str[j];
//		}
//
//		delete[] str;
//
//		str = newStr;
//		length = length + obj.length;
//
//		return *this;
//	}
//
//	bool operator==(const MyString& obj) const
//	{
//		if (length != obj.length)
//		{
//			return false;
//		}
//
//		for (int i = 0; i < length; i++)
//		{
//			if (str[i] != obj.str[i])
//			{
//				return false;
//			}
//		}
//
//		return true;
//	}
//
//	bool operator!=(const MyString& obj) const
//	{
//		if (*this == obj)
//		{
//			return false;
//		}
//		else
//		{
//			return true;
//		}
//	}
//
//	bool operator<(const MyString& obj) const
//	{
//		int i = 0;
//
//		while (str[i] != '\0' && obj.str[i] != '\0')
//		{
//			if (str[i] < obj.str[i])
//			{
//				return true;
//			}
//
//			if (str[i] > obj.str[i])
//			{
//				return false;
//			}
//
//			i++;
//		}
//
//		if (length < obj.length)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool operator>(const MyString& obj) const
//	{
//		if (*this == obj)
//			return false;
//
//		if (*this < obj)
//			return false;
//
//		return true;
//	}
//
//	char& operator[](int index)
//	{
//		if (index < 0 || index >= length)
//		{
//			cout << "Index out of range\n";
//			exit(1);
//		}
//		return str[index];
//	}
//
//	MyString operator()() const
//	{
//		MyString temp;
//
//		temp.length = length;
//		temp.str = new char[length + 1];
//
//		int k = 0;
//
//		for (int i = length - 1; i >= 0; i--)
//		{
//			temp.str[k++] = str[i];
//		}
//
//		temp.str[length] = '\0';
//
//		return temp;
//	}
//
//	friend ostream& operator<<(ostream& out, const MyString& obj);
//
//	friend istream& operator>>(istream& in, MyString& obj);
//
//	int getlength() const
//	{
//		return length;
//	}
//
//	~MyString()
//	{
//		delete[] str;
//		str = nullptr;
//	}
//};
//
//ostream& operator<<(ostream& out, const MyString& obj)
//{
//	out << obj.str;
//	return out;
//}
//
//istream& operator>>(istream& in, MyString& obj)
//{
//	char temp[1000];
//	in.getline(temp, 1000);
//
//	obj.length = obj.stringLength(temp);
//
//	delete[] obj.str;
//	obj.str = new char[obj.length + 1];
//
//	for (int i = 0; i <= obj.length; i++)
//	{
//		obj.str[i] = temp[i];
//	}
//
//	return in;
//}
//
//void menu()
//{
//	cout << "============================================" << endl;
//	cout << "Custom Text Processing Engine" << endl;
//	cout << "============================================" << endl;
//	cout << "1.  Enter new string" << endl;
//	cout << "2.  Display string" << endl;
//	cout << "3.  Show length" << endl;
//	cout << "4.  Count words" << endl;
//	cout << "5.  Convert to uppercase" << endl;
//	cout << "6.  Convert to lowercase" << endl;
//	cout << "7.  Convert to sentence case" << endl;
//	cout << "8.  Reverse string" << endl;
//	cout << "9.  Concatenate another string" << endl;
//	cout << "10.  Compare with another string" << endl;
//	cout << "11.  Access character using index[]" << endl;
//	cout << "12.  Test assignment operator =" << endl;
//	cout << "13.  Test function call operator ()" << endl;
//	cout << "14.  Exit" << endl;
//	cout << "--------------------------------------------" << endl;
//}
//
//void exitProgram()
//{
//	cout << "\nExited Succesfully" << endl;
//}
//
//int main()
//{
//	MyString s1, s2, result;
//	int choice;
//
//	do
//	{
//		menu();
//
//		do
//		{
//			cout << "Enter your Choice: ";
//			cin >> choice;
//
//			if (cin.fail())
//			{
//				cout << "ERROR: You can only enter numbers !!\n\n";
//
//				cin.clear();
//				cin.ignore(10000, '\n');
//			}
//
//			else if (choice <= 0 || choice > 14)
//			{
//				cout << "ERROR: Enter a number between 1 and 14 !!\n\n";
//			}
//
//		} while (cin.fail() || choice <= 0 || choice > 14);
//
//		switch (choice)
//		{
//		case 1:
//		{
//			cout << "Enter string: ";
//			cin.ignore(10000, '\n');
//			cin >> s1;
//			break;
//		}
//
//		case 2:
//		{
//			s1.display();
//			break;
//		}
//
//		case 3:
//		{
//			cout << "Length: " << s1.getlength() << endl;
//			break;
//		}
//
//		case 4:
//		{
//			cout << "Word count: " << s1.countWords() << endl;
//			break;
//		}
//
//		case 5:
//		{
//			s1.toUpperCase();
//			cout << "Uppercase: " << s1 << endl;
//			break;
//		}
//
//		case 6:
//		{
//			s1.toLowerCase();
//			cout << "Lowercase: " << s1 << endl;
//			break;
//		}
//
//		case 7:
//		{
//			s1.toSentenceCase();
//			cout << "Sentence case: " << s1 << endl;
//			break;
//		}
//
//		case 8:
//		{
//			result = s1.reverse();
//			cout << "Reversed: " << result << endl;
//			break;
//		}
//
//		case 9:
//		{
//			cout << "Enter second string: ";
//			cin.ignore(10000, '\n');
//			cin >> s2;
//
//			result = s1 + s2;
//			cout << "Concatenated: " << result << endl;
//			break;
//		}
//
//		case 10:
//		{
//			cout << "Enter second string: ";
//			cin.ignore(10000, '\n');
//			cin >> s2;
//
//			cout << "Equal? " << (s1 == s2 ? "Yes" : "No") << endl;
//			cout << "Less than? " << (s1 < s2 ? "Yes" : "No") << endl;
//			cout << "Greater than? " << (s1 > s2 ? "Yes" : "No") << endl;
//			break;
//		}
//
//		case 11:
//		{
//			int index;
//			cout << "Enter index: ";
//			cin >> index;
//
//			cout << "Character: " << s1[index] << endl;
//			break;
//		}
//
//		case 12:
//		{
//			cout << "Enter new string for assignment: ";
//			cin.ignore(10000, '\n');
//			cin >> s2;
//
//			s1 = s2;
//			cout << "After assignment: " << s1 << endl;
//			break;
//		}
//
//		case 13:
//		{
//			result = s1();  // function call operator
//			cout << "Reversed (using operator()): " << result << endl;
//			break;
//		}
//
//		case 14:
//		{
//			exitProgram();
//			return 0;
//			break;
//		}
//
//		default:
//			cout << "Invalid choice!\n";
//		}
//
//	} while (choice != 14);
//
//
//	cout << "\n" << endl;
//	system("pause");
//	return 0;
//}