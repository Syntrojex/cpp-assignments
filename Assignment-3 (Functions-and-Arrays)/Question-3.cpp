//#include <iostream>
//using namespace std;
//
//void combine(int arr1[], int size1, int arr2[], int size2, int newArray[], int sizeofNew)
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;  //start index for new array
//
//	while (i < size1 && j < size2)
//	{
//		if (arr1[i] < arr2[j])
//		{
//			newArray[k] = arr1[i];
//			k++;
//			i++;
//		}
//		else if (arr1[i] > arr2[j])
//		{
//			newArray[k] = arr2[j];
//			k++;
//			j++;
//		}
//		else
//		{
//			newArray[k++] = arr1[i++];
//			newArray[k++] = arr2[j++];
//		}
//	}
//
//
//	// copying remaining elements of array 1
//	while (i < size1)
//	{
//		newArray[k] = arr1[i];
//		k++;
//		i++;
//	}
//
//	// copying remaining elements of array 2
//	while (j < size2)
//	{
//		newArray[k] = arr2[j];
//		k++;
//		j++;
//	}
//
//
//}
//
//int main()
//{
//	int arr1[10];
//	int arr2[10];
//	int size1 = sizeof(arr1) / sizeof(int);
//	int size2 = sizeof(arr2) / sizeof(int);
//
//
//	//Getting inputs
//	cout << "Enter " << size1 << " Elements in Array 1: " << endl;
//	for (int i = 0; i < size1; i++)
//	{
//		cout << "Element " << i << ": ";
//		cin >> arr1[i];
//	}
//	cout << "\nEnter " << size2 << " Elements in Array 2: " << endl;
//	for (int i = 0; i < size2; i++)
//	{
//		cout << "Element " << i << ": ";
//		cin >> arr2[i];
//	}
//
//
//	//sorting both arrays
//	for (int i = 0; i < size1; i++)
//	{
//		for (int j = i + 1; j < size1; j++)
//		{
//			if (arr1[i] > arr1[j])
//			{
//				int temp = arr1[i];
//				arr1[i] = arr1[j];
//				arr1[j] = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i < size2; i++)
//	{
//		for (int j = i + 1; j < size2; j++)
//		{
//			if (arr2[i] > arr2[j])
//			{
//				int temp = arr2[i];
//				arr2[i] = arr2[j];
//				arr2[j] = temp;
//			}
//		}
//	}
//
//	cout << endl;
//
//	//showing the sorted arrays
//	cout << "Sorted Array 1: ";
//	for (int i = 0; i < size1; i++)
//	{
//		cout << arr1[i] << " ";
//	}
//
//	cout << "\nSorted Array 2: ";
//	for (int i = 0; i < size2; i++)
//	{
//		cout << arr2[i] << " ";
//	}
//
//	int newArray[20];
//	int sizeofNew = size1 + size2;
//
//	combine(arr1, size1, arr2, size2, newArray, sizeofNew);
//
//
//	// showing new combined array
//	cout << "\n\nCombined Array: ";
//	for (int i = 0; i < sizeofNew; i++)
//	{
//		cout << newArray[i] << " ";
//	}
//
//	cout << endl;
//	cout << endl;
//	system("pause");
//	return 0;
//}