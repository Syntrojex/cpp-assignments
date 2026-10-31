//#include <iostream>
//using namespace std;
//
//void sort_and_finding_kthLargest(int arr[], int size)   // Void is used because nothing is returned
//{
//
//	// First we have to sort array by Bubble sort
//	int temp;
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			if (arr[i] < arr[j])
//			{
//				temp = arr[j];
//				arr[j] = arr[i];
//				arr[i] = temp;
//			}
//		}
//	}
//	cout << endl;
//
//
//	// showing Sorted Array
//	cout << "Sorted Array in ascending order: ";
//	for (int x = 0; x < size; x++)
//	{
//		cout << arr[x] << " ";
//	}
//	cout << endl;
//
//
//	int k;
//	// Input Validity check
//	do
//	{
//		cout << "Enter K to find k-th Largest Value: ";
//		cin >> k;
//		if (k <= 0)
//		{
//			cout << "Error: Value of k must be greater than 0!" << endl;
//			cout << endl;
//		}
//		else if (k > 10)
//		{
//			cout << "Error: value of k must be less than 10!!" << endl;
//			cout << endl;
//		}
//	} while (k <= 0 || k > 10);
//
//	cout << "\n--------------------------------------" << endl;
//	cout << k << "-th Largest Number is: " << arr[size - k] << endl;
//
//}
//
//int main()
//{
//	int array[10];
//	int size = sizeof(array) / sizeof(int);
//
//	// Getting array from user
//	cout << "Enter 10 Elements in Array: " << endl;
//	for (int i = 0; i < size; i++)
//	{
//		cout << "Element " << i << ": ";
//		cin >> array[i];
//	}
//
//
//	// Showing Array to user
//	cout << "Original Array: ";
//	for (int i = 0; i < size; i++)
//	{
//		cout << array[i] << " ";
//	}
//	cout << endl;
//
//	sort_and_finding_kthLargest(array, size);
//
//
//	cout << endl;
//	system("pause");
//	return 0;
//}