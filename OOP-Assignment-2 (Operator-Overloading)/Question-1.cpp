//#include<iostream>
//using namespace std;
//
//class Rational
//{
//private:
//
//	int numerator;
//	int denominator;
//
//	void check()
//	{
//		while (denominator == 0)
//		{
//			cout << "Denominator cannot be zero!! Enter again: ";
//			cin >> denominator;
//		}
//	}
//
//	void fixSign()
//	{
//		if (denominator < 0)
//		{
//			numerator = -numerator;
//			denominator = -denominator;
//		}
//	}
//
//	int gcd(int a, int b) // gcd sab rational numbers ki cutting kre ga
//	{
//		a = (a < 0) ? -a : a;
//		b = (b < 0) ? -b : b;
//		return b == 0 ? a : gcd(b, a % b);
//	}
//
//	void reduce()
//	{
//		int hcf = gcd(numerator, denominator);
//
//		numerator /= hcf;
//		denominator /= hcf;
//	}
//
//public:
//	Rational()
//	{
//		numerator = 0;
//		denominator = 1;
//	}
//
//	Rational(int num, int den)
//	{
//		numerator = num;
//		denominator = den;
//
//		check();
//		fixSign();
//		reduce();
//
//	}
//
//	Rational(int num)
//	{
//		numerator = num;
//		denominator = 1;
//	}
//
//	Rational(const Rational& obj)
//	{
//		numerator = obj.numerator;
//		denominator = obj.denominator;
//	}
//
//	double toDecimal() const
//	{
//		return static_cast<double>(numerator) / denominator;
//	}
//
//	Rational reciprocal() const
//	{
//		return Rational(denominator, numerator);
//	}
//
//	void display() const
//	{
//		cout << numerator << "/" << denominator << endl;
//	}
//
//	Rational operator+(const Rational& obj) const
//	{
//		int new_num = numerator * obj.denominator + obj.numerator * denominator;
//		int new_den = denominator * obj.denominator;
//
//		return Rational(new_num, new_den); // ye two parameter wale constructor ko call kre ga 
//	}
//
//	Rational operator-(const Rational& obj) const
//	{
//		int new_num = numerator * obj.denominator - obj.numerator * denominator;
//		int new_den = denominator * obj.denominator;
//
//		return Rational(new_num, new_den);
//	}
//
//	Rational operator*(const Rational& obj) const
//	{
//		int new_num = numerator * obj.numerator;
//		int new_den = denominator * obj.denominator;
//
//		return Rational(new_num, new_den);
//	}
//
//	Rational operator/(const Rational& obj) const
//	{
//		if (obj.numerator == 0)
//		{
//			cout << "Error: Division by zero is not possible!" << endl;
//			exit(1);  // ye yehan pr foran program end kr de ga return 0 is liye nhi kr skte kio k return type class ha jab k 0 integer ha 
//		}
//
//		int new_num = numerator * obj.denominator;
//		int new_den = denominator * obj.numerator;
//
//		return Rational(new_num, new_den);
//	}
//
//	Rational& operator+=(const Rational& obj)
//	{
//		numerator = numerator * obj.denominator + denominator * obj.numerator;
//		denominator = denominator * obj.denominator;
//
//		fixSign();
//		reduce();
//
//		return *this;
//	}
//
//	Rational& operator-=(const Rational& obj)
//	{
//		numerator = numerator * obj.denominator - denominator * obj.numerator;
//		denominator = denominator * obj.denominator;
//
//		fixSign();
//		reduce();
//
//		return *this;
//	}
//
//	Rational& operator*=(const Rational& obj)
//	{
//		numerator = numerator * obj.numerator;
//		denominator = denominator * obj.denominator;
//
//		fixSign();
//		reduce();
//
//		return *this;
//	}
//
//	Rational& operator/=(const Rational& obj)
//	{
//		if (obj.numerator == 0)
//		{
//			cout << "Error: Division by zero is not possible!" << endl;
//			exit(1);
//		}
//
//		numerator = numerator * obj.denominator;
//		denominator = denominator * obj.numerator;
//
//		fixSign();
//		reduce();
//
//		return *this;
//	}
//
//	bool operator==(const Rational& obj) const
//	{
//		if (numerator * obj.denominator == denominator * obj.numerator)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool operator!=(const Rational& obj) const
//	{
//		if (numerator * obj.denominator != denominator * obj.numerator)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool operator<(const Rational& obj) const
//	{
//		if (numerator * obj.denominator < denominator * obj.numerator)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool operator>(const Rational& obj) const
//	{
//		if (numerator * obj.denominator > denominator * obj.numerator)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool operator<=(const Rational& rhs) const
//	{
//		if (numerator * rhs.denominator <= denominator * rhs.numerator)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool operator>=(const Rational& rhs) const
//	{
//		if (numerator * rhs.denominator >= denominator * rhs.numerator)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	Rational& operator++() // pre increment
//	{
//		numerator += denominator;
//		reduce();
//		return *this;
//	}
//
//	Rational operator++(int) // post increment
//	{
//		Rational temp = *this;
//		numerator += denominator;
//		reduce();
//		return temp;
//	}
//
//	Rational& operator--() // pre decremnt
//	{
//		numerator -= denominator;
//		reduce();
//		return *this;
//	}
//
//	Rational operator--(int) // post decrement
//	{
//		Rational temp = *this;
//		numerator -= denominator;
//		reduce();
//		return temp;
//	}
//
//	// Function call 
//	Rational operator()() const
//	{
//		if (numerator == 0)
//		{
//			cout << "Error!" << endl;
//			return *this;
//		}
//		return Rational(denominator, numerator);
//	}
//
//	// Stream Operator
//	friend ostream& operator<<(ostream& output, const Rational& r)
//	{
//		output << r.numerator << "/" << r.denominator;
//		return output;
//	}
//
//	friend istream& operator>>(istream& input, Rational& r)
//	{
//		cout << "\nEnter Numerator: ";
//		input >> r.numerator;
//
//		do
//		{
//			cout << "Enter Denominator: ";
//			input >> r.denominator;
//
//			if (r.denominator == 0)
//			{
//				cout << "Denominator cannot be zero!" << endl;
//				cout << endl;
//			}
//
//		} while (r.denominator == 0);
//
//		r.fixSign();
//		r.reduce();
//
//		return input;
//	}
//};
//
//void menu()
//{
//	cout << "============================================" << endl;
//	cout << "           Rational Number System           " << endl;
//	cout << "============================================" << endl;
//	cout << "1.  Add two rational numbers" << endl;
//	cout << "2.  Subtract two rational numbers" << endl;
//	cout << "3.  Multiply two rational numbers" << endl;
//	cout << "4.  Divide two rational numbers" << endl;
//	cout << "5.  Compound assignment operations" << endl;
//	cout << "6.  Compare two rational numbers" << endl;
//	cout << "7.  Convert to decimal" << endl;
//	cout << "8.  Reciprocal(member function)" << endl;
//	cout << "9.  Prefix & Postfix Increment" << endl;
//	cout << "10. Prefix & Postfix Decrement" << endl;
//	cout << "11. Function call operator ()" << endl;
//	cout << "12. Operations with integers" << endl;
//	cout << "13. Exit" << endl;
//	cout << "--------------------------------------------" << endl;
//
//}
//
//void exit()
//{
//	cout << "\nExited Succesfully" << endl;
//}
//
//int main()
//{
//	Rational r1, r2, result;
//
//	cout << "Enter first rational Number: ";
//	cin >> r1;
//
//	cout << "\nEnter second rational Number: ";
//	cin >> r2;
//
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
//			else if (choice <= 0 || choice > 13)
//			{
//				cout << "ERROR: Enter a number between 1 and 13 !!\n\n";
//			}
//
//		} while (cin.fail() || choice <= 0 || choice > 13);
//
//		switch (choice)
//		{
//		case 1:
//		{
//			cout << "Addition: " << (r1 + r2) << endl;
//			break;
//		}
//
//		case 2:
//		{
//			cout << "Subtraction: " << (r1 - r2) << endl;
//			break;
//		}
//
//		case 3:
//		{
//			cout << "Multiplication: " << (r1 * r2) << endl;
//			break;
//		}
//
//		case 4:
//		{
//			cout << "Division: " << (r1 / r2) << endl;
//			break;
//		}
//
//		case 5:
//		{
//			result = r1;
//			result += r2;
//			cout << "r1 += r2: " << result << endl;
//
//			result = r1;
//			result -= r2;
//			cout << "r1 -= r2: " << result << endl;
//
//			result = r1;
//			result *= r2;
//			cout << "r1 *= r2: " << result << endl;
//
//			result = r1;
//			result /= r2;
//			cout << "r1 /= r2: " << result << endl;
//			break;
//		}
//
//		case 6:
//		{
//			cout << "NOTE: 0 menas false and 1 means true!!" << endl;
//			cout << "Equal? " << (r1 == r2) << endl;
//			cout << "Not Equal? " << (r1 != r2) << endl;
//			cout << "Less? " << (r1 < r2) << endl;
//			cout << "Greater? " << (r1 > r2) << endl;
//			cout << "Less Equal? " << (r1 <= r2) << endl;
//			cout << "Greater Equal? " << (r1 >= r2) << endl;
//			break;
//		}
//
//		case 7:
//		{
//			cout << "Decimal of r1: " << r1.toDecimal() << endl;
//			cout << "Decimal of r2: " << r2.toDecimal() << endl;
//			break;
//		}
//
//		case 8:
//		{
//			cout << "Reciprocal of r1: " << r1.reciprocal() << endl;
//			cout << "Reciprocal of r2: " << r2.reciprocal() << endl;
//			break;
//		}
//
//		case 9:
//		{
//			cout << "Prefix Increment ++r1: " << ++r1 << endl;
//			cout << "Postfix Increment r1++: " << r1++ << endl;
//			cout << "After postfix Increment r1: " << r1 << endl;
//			break;
//		}
//
//		case 10:
//		{
//			cout << "Prefix decrement --r1: " << --r1 << endl;
//			cout << "Postfix decrement  r1--: " << r1-- << endl;
//			cout << "After postfix decrement  r1: " << r1 << endl;
//			break;
//		}
//
//		case 11:
//		{
//			cout << "r1(): " << r1() << endl;
//			cout << "r2(): " << r2() << endl;
//			break;
//		}
//
//		case 12:
//		{
//			cout << "r1 + 2: " << (r1 + 2) << endl;
//			break;
//		}
//
//		case 13:
//		{
//			exit();
//			return 0;
//		}
//
//		default:
//		{
//			cout << "Invalid choice!\n";
//			break;
//		}
//
//		}
//
//	} while (choice != 13);
//
//
//	cout << "\n" << endl;
//	system("pause");
//	return 0;
//}