#include<iostream>
using namespace std;
int main()
{
	float absolutes;
	cout << "Enter your Absolutes (0 to 100): ";
	cin >> absolutes;
	if (absolutes > 100 || absolutes < 0)
	{
		cout << "Invalid Input! Please enter marks between 0 and 100" << endl;
	}
	else
	{
		if (absolutes >= 90)
		{
			cout << "----------Result----------" << endl;
			cout << "Grade: A+" << endl;
			cout << "CGPA: 4.00" << endl;
		}
		else if (absolutes >= 86 && absolutes < 90)
		{
			cout << "----------Result----------" << endl;
			cout << "Grade: A" << endl;
			cout << "CGPA: 4.00" << endl;
		}
		else if (absolutes >= 82 && absolutes < 86)
		{
			cout << "----------Result----------" << endl;
			cout << "Grade: A-" << endl;
			cout << "CGPA: 3.67" << endl;
		}
		else if (absolutes >= 78 && absolutes < 82)
		{
			cout << "----------Result----------" << endl;
			cout << "Grade: B+" << endl;
			cout << "CGPA: 3.33" << endl;
		}
		else if (absolutes >= 74 && absolutes < 78)
		{
			cout << "----------Result----------" << endl;
			cout << "Grade: B" << endl;
			cout << "CGPA: 3.00" << endl;
		}
		else if (absolutes >= 70 && absolutes < 74)
		{
			cout << "----------Result----------" << endl;
			cout << "Grade: B-" << endl;
			cout << "CGPA: 2.67" << endl;
		}
		else if (absolutes >= 66 && absolutes < 70)
		{
			cout << "----------Result----------" << endl;
			cout << "Grade: C+" << endl;
			cout << "CGPA: 2.33" << endl;
		}
		else if (absolutes >= 62 && absolutes < 66)
		{
			cout << "----------Result----------" << endl;
			cout << "Grade: C" << endl;
			cout << "CGPA: 2.00" << endl;
		}
		else if (absolutes >= 58 && absolutes < 62)
		{
			cout << "----------Result----------" << endl;
			cout << "Grade: C-" << endl;
			cout << "CGPA: 1.67" << endl;
		}
		else if (absolutes >= 54 && absolutes < 58)
		{
			cout << "----------Result----------" << endl;
			cout << "Grade: D+" << endl;
			cout << "CGPA: 1.33" << endl;
		}
		else if (absolutes >= 50 && absolutes < 54)
		{
			cout << "----------Result----------" << endl;
			cout << "Grade: D" << endl;
			cout << "CGPA: 1.00" << endl;
		}
		else
		{
			cout << "----------Result----------" << endl;
			cout << "Grade: F" << endl;
			cout << "CGPA: 0.00" << endl;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}
