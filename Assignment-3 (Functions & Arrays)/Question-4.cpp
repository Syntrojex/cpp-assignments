//#include <iostream>
//using namespace std;
//
//int function(int arr[], int size)
//{
//	int length = 0;
//
//	for (int i = 0; i < size; i++)
//	{
//		int count = 0;
//		int currentMax = 0;
//
//		for (int j = 0; j < size; j++)
//		{
//			if (j == i)
//			{
//				continue;
//			}
//
//			if (arr[j] == 1)
//			{
//				count++;
//				if (count > currentMax)
//				{
//					currentMax = count;
//				}
//			}
//			else
//			{
//				count = 0;
//			}
//		}
//		if (currentMax > length)
//		{
//			length = currentMax;
//		}
//	}
//
//	return length;
//}
//
//int main()
//{
//	int size;
//	int arr[1000];
//
//	do
//	{
//		cout << "Enter Size of Array: ";
//		cin >> size;
//
//		if (size <= 0)
//		{
//			cout << "Error: Size must be greater than 0!!" << endl;
//			cout << endl;
//		}
//	} while (size <= 0);
//
//	cout << endl;
//
//	// getting array from user
//	cout << "NOTE: Try to enter Binary Numbers(0 or 1)!!" << endl;
//	cout << "\nEnter " << size << " Elements in Array: " << endl;
//	for (int i = 0; i < size; i++)
//	{
//		cout << "Enter Element " << i << ": ";
//		cin >> arr[i];
//		if (arr[i] != 0)    //taake array me agar koi element 1 na ho to wo 1 ban jay
//		{
//			arr[i] = 1;
//		}
//	}
//
//	// showing entered array
//	cout << "\nEntered Array: ";
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << " ";
//	}
//
//
//	int len = function(arr, size);
//	cout << "\n\nMaximum Length of with consecutive 1's after deleting one element: " << len << endl;
//
//
//	cout << "\n" << endl;
//	system("pause");
//	return 0;
//}