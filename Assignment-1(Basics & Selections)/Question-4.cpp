#include<iostream>
#include<iomanip>     // to ensure 2 decimal spaces
using namespace std;
int main()
{
	// program is made for a fixed course number of 9
	float grade1, grade2, grade3, grade4, grade5, grade6, grade7, grade8, grade9;
	float numerator, denominator;
	int credit1, credit2, credit3, credit4, credit5, credit6, credit7, credit8, credit9;
	float sgpa;    

	// for course 1
	cout << "Enter grade for Course 1: " << endl;
	cin >> grade1;
	cout << "Enter credit hours of Course 1: " << endl;
	cin >> credit1;

	// for course 2
	cout << "Enter grade for Course 2: " << endl;
	cin >> grade2;
	cout << "Enter credit hours of Course 2: " << endl;
	cin >> credit2;

	// for course 3
	cout << "Enter grade for Course 3: " << endl;
	cin >> grade3;
	cout << "Enter credit hours of Course 3: " << endl;
	cin >> credit3;

	// for course 4
	cout << "Enter grade for Course 4: " << endl;
	cin >> grade4;
	cout << "Enter credit hours of Course 4: " << endl;
	cin >> credit4;

	// for course 5
	cout << "Enter grade for Course 5: " << endl;
	cin >> grade5;
	cout << "Enter credit hours of Course 5: " << endl;
	cin >> credit5;

	// for course 6
	cout << "Enter grade for Course 6: " << endl;
	cin >> grade6;
	cout << "Enter credit hours of Course 6: " << endl;
	cin >> credit6;

	// for course 7
	cout << "Enter grade for Course 7: " << endl;
	cin >> grade7;
	cout << "Enter credit hours of Course 7: " << endl;
	cin >> credit7;

	// for course 8
	cout << "Enter grade for Course 8: " << endl;
	cin >> grade8;
	cout << "Enter credit hours of Course 8: " << endl;
	cin >> credit8;

	// for course 9
	cout << "Enter grade for Course 9: " << endl;
	cin >> grade9;
	cout << "Enter credit hours of Course 9: " << endl;
	cin >> credit9;

	// validity check so that grade must lie between 0 to 4
	if (grade1 < 0 || grade1>4 || grade2 < 0 || grade2>4 || grade3 < 0 || grade3>4 || grade4 < 0 || grade4>4 || grade5 < 0 || grade5>4 || grade6 < 0 || grade6>4 || grade7 < 0 || grade7 > 4 || grade8 < 0 || grade8 > 4 || grade9 < 0 || grade9 > 4)
	{
		cout << "Grade must lie between 0 and 4" << endl;
	}
	else
	{
		// finding sigma credits means sum of all credit hours
		denominator = credit1 + credit2 + credit3 + credit4 + credit5 + credit6 + credit7 + credit8 + credit9;
		
		// expressing gradepoints multiply by credit hours
		numerator = (grade1 * credit1) + (grade2 * credit2) + (grade3 * credit3) + (grade4 * credit4) + (grade5 * credit5) + (grade6 * credit6) + (grade7 * credit7) + (grade8 * credit8) + (grade9 * credit9);

		sgpa = numerator / denominator;
		
		cout << "SGPA: " << fixed << setprecision(2) << sgpa << endl;      // precison of 2 decimal spaces because sgpa has 2 decimals spaces
	}

	cout << endl;
	system("pause");
	return 0;
}