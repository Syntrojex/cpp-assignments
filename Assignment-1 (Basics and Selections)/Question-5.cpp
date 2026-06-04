//#include<iostream>
//using namespace std;
//int main()
//{
//	int code;
//	cout << "Enter the 5 digit ZIP-code to see its city and province: ";
//	cin >> code;
//	
//
//	if (code < 10000 || code > 99999)   // checking if code is 5 digit or not
//	{
//		cout << "Invalid code! Please enter a 5 digit code " << endl;
//	}
//	else
//	{
//		int zip = code / 1000;
//		if (zip == 75)
//		{
//			cout << "City name: Karachi" << endl;
//			cout << "Province: Sindh" << endl;
//		}
//		else if (zip == 54)
//		{
//			cout << "City name: Lahore" << endl;
//			cout << "Province: Punjab" << endl;
//		}
//		else if (zip == 51 || zip == 44)
//		{
//			cout << "City name: Islamabad" << endl;
//			cout << "Province: Federal capital (Punjab)" << endl;
//		}
//		else if (zip == 42)
//		{
//			cout << "City name: Faisalabad" << endl;
//			cout << "Province: Punjab" << endl;
//		}
//		else if (zip == 71)
//		{
//			cout << "City name: Hyderabad" << endl;
//			cout << "Province: Sindh" << endl;
//		}
//		else if (zip == 65 || zip == 87)
//		{
//			cout << "City name: Quetta" << endl;
//			cout << "Province: Balochistan" << endl;
//		}
//		else if (zip == 25 || zip == 24)
//		{
//			cout << "City name: Peshawar" << endl;
//			cout << "Province: KPK" << endl;
//		}
//		else
//		{
//			cout << "ZIP code not found!" << endl;
//		}
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}