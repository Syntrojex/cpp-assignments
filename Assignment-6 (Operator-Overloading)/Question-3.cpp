//#include<iostream>
//using namespace std;
//
//class CalendarDate {
//private:
//	int day;
//	int month;
//	int year;
//
//public:
//
//	bool isLeapYear() const
//	{
//		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//	}
//
//	int daysInMonth(int m, int y) const
//	{
//		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
//		{
//			return 31;
//		}
//
//		if (m == 4 || m == 6 || m == 9 || m == 11)
//		{
//			return 30;
//		}
//
//		if (m == 2)
//		{
//			return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) ? 29 : 28;
//		}
//
//		return 0;
//	}
//
//	bool isValid() const
//	{
//		if (month < 1 || month > 12)
//		{
//			return false;
//		}
//		if (day < 1 || day > daysInMonth(month, year))
//		{
//			return false;
//		}
//
//		return true;
//	}
//
//	CalendarDate()
//	{
//		day = 1;
//		month = 1;
//		year = 2000;
//	}
//
//	CalendarDate(int d, int m, int y)
//	{
//		day = d;
//		month = m;
//		year = y;
//
//		if (!isValid())
//		{
//			cout << "Invalid Date! Reseting to 01-01-2000" << endl;
//			day = 1;
//			month = 1;
//			year = 2000;
//		}
//	}
//
//	void display() const
//	{
//		if (day < 10)
//		{
//			cout << "0";
//		}
//		cout << day << "-";
//
//		if (month < 10)
//		{
//			cout << "0";
//		}
//		cout << month << "-";
//		cout << year << endl;
//	}
//
//	void nextDay()
//	{
//		day++;
//
//		if (day > daysInMonth(month, year))
//		{
//			day = 1;
//			month++;
//
//			if (month > 12)
//			{
//				month = 1;
//				year++;
//			}
//		}
//	}
//
//	void prevDay()
//	{
//		day--;
//
//		if (day < 1)
//		{
//			month--;
//
//			if (month < 1)
//			{
//				month = 12;
//				year--;
//			}
//
//			day = daysInMonth(month, year);
//		}
//	}
//
//	void addDays(int n)
//	{
//		while (n--)
//		{
//			nextDay();
//		}
//	}
//
//	void subtractDays(int n)
//	{
//		while (n--)
//		{
//			prevDay();
//		}
//	}
//
//	CalendarDate operator+(int n)
//	{
//		CalendarDate temp = *this;
//		temp.addDays(n);
//		return temp;
//	}
//
//	CalendarDate operator-(int n)
//	{
//		CalendarDate temp = *this;
//		temp.subtractDays(n);
//		return temp;
//	}
//
//	CalendarDate& operator+=(int n)
//	{
//		addDays(n);
//		return *this;
//	}
//
//	CalendarDate& operator-=(int n)
//	{
//		subtractDays(n);
//		return *this;
//	}
//
//	int operator-(const CalendarDate& obj) const
//	{
//		CalendarDate temp1 = *this;
//		CalendarDate temp2 = obj;
//
//		int count = 0;
//
//		while (!(temp1.year == temp2.year && temp1.month == temp2.month && temp1.day == temp2.day)) {
//
//			if (temp1.year > temp2.year || (temp1.year == temp2.year && temp1.month > temp2.month) || (temp1.year == temp2.year && temp1.month == temp2.month && temp1.day > temp2.day))
//			{
//				temp2.nextDay();
//				count++;
//			}
//			else
//			{
//				temp1.nextDay();
//				count++;
//			}
//		}
//
//		return count;
//	}
//
//	bool operator==(const CalendarDate& obj) const
//	{
//		if (day == obj.day && month == obj.month && year == obj.year)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool operator!=(const CalendarDate& obj) const
//	{
//		return !(*this == obj);
//	}
//
//	bool operator<(const CalendarDate& obj) const
//	{
//		if (year != obj.year)
//		{
//			return year < obj.year;
//		}
//		if (month != obj.month)
//		{
//			return month < obj.month;
//		}
//		return day < obj.day;
//	}
//
//	bool operator>(const CalendarDate& obj) const
//	{
//		return obj < *this;
//	}
//
//	CalendarDate& operator++()
//	{
//		nextDay();
//		return *this;
//	}
//
//	CalendarDate operator++(int)
//	{
//		CalendarDate temp = *this;
//		nextDay();
//		return temp;
//	}
//
//	CalendarDate& operator--()
//	{
//		prevDay();
//		return *this;
//	}
//
//	CalendarDate operator--(int)
//	{
//		CalendarDate temp = *this;
//		prevDay();
//		return temp;
//	}
//
//	void operator()() const
//	{
//		display();
//	}
//
//	friend ostream& operator<<(ostream& out, const CalendarDate& obj);
//
//	friend istream& operator>>(istream& in, CalendarDate& obj);
//};
//
//ostream& operator<<(ostream& output, const CalendarDate& obj)
//{
//	if (obj.day < 10)
//	{
//		output << "0";
//	}
//
//	output << obj.day << "-";
//	if (obj.month < 10)
//	{
//		output << "0";
//	}
//
//	output << obj.month << "-";
//	output << obj.year;
//	return output;
//}
//
//istream& operator>>(istream& input, CalendarDate& obj)
//{
//	cout << "Enter Day: ";
//	input >> obj.day;
//	cout << "Enter Month: ";
//	input >> obj.month;
//	cout << "Enter Year: ";
//	input >> obj.year;
//
//	if (!obj.isValid())
//	{
//		cout << "Invalid Date! Reseting it to: 01-01-2000\n";
//		obj.day = 1;
//		obj.month = 1;
//		obj.year = 2000;
//	}
//
//	return input;
//}
//
//void menu()
//{
//	cout << "============================================" << endl;
//	cout << "Calendar Management System" << endl;
//	cout << "============================================" << endl;
//	cout << "1.  Enter a new date" << endl;
//	cout << "2.  Display date" << endl;
//	cout << "3.  Add days" << endl;
//	cout << "4.  Subtract days" << endl;
//	cout << "5.  Compare two dates" << endl;
//	cout << "6.  Find difference between two dates" << endl;
//	cout << "7.  Test increment operators(++prefix & postfix)" << endl;
//	cout << "8.  Test decrement operators(--prefix & postfix)" << endl;
//	cout << "9.  Test compound operators += and -=" << endl;
//	cout << "10.  Check leap year" << endl;
//	cout << "11.  Display in all formats(function call operator)" << endl;
//	cout << "12.  Exit--------------------------------------------" << endl;
//}
//
//
//int main()
//{
//	CalendarDate d1, d2;
//	int n;
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
//			else if (choice <= 0 || choice > 12)
//			{
//				cout << "ERROR: Enter a number between 1 and 12 !!\n\n";
//			}
//
//		} while (cin.fail() || choice <= 0 || choice > 12);
//
//		switch (choice)
//		{
//
//		case 1:
//			cout << "Enter date: ";
//			cin >> d1;
//			break;
//
//		case 2:
//			cout << d1 << endl;
//			break;
//
//		case 3:
//			cout << "Enter days: ";
//			cin >> n;
//			d1.addDays(n);
//			cout << d1 << endl;
//			break;
//
//		case 4:
//			cout << "Enter days: ";
//			cin >> n;
//			d1.subtractDays(n);
//			cout << d1 << endl;
//			break;
//
//		case 5:
//			cout << "Enter second date: ";
//			cin >> d2;
//			cout << (d1 < d2) << endl;
//			break;
//
//		case 6:
//			cout << "Enter second date: ";
//			cin >> d2;
//			cout << (d1 - d2) << " days\n";
//			break;
//
//		case 7:
//			++d1;
//			cout << d1 << endl;
//			break;
//
//		case 8:
//			--d1;
//			cout << d1 << endl;
//			break;
//
//		case 9:
//			cout << "Enter n: ";
//			cin >> n;
//			d1 += n;
//			cout << d1 << endl;
//			break;
//
//		case 10:
//			cout << d1.isLeapYear() << endl;
//			break;
//
//		case 11:
//			d1();
//			break;
//
//		case 12:
//			cout << "Exited program!!" << endl;
//			return 0;
//		}
//
//	} while (choice != 12);
//
//
//	cout << "\n" << endl;
//	system("pause");
//	return 0;
//}