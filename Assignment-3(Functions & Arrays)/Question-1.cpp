//#include <iostream>
//using namespace std;
//int main()
//{
//	int array[10];
//	int size = sizeof(array) / sizeof(int);
//	int duplicate = 0;
//
//	//Taking inputs
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
//
//	// Removing duplicates 
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = i + 1; j < size; j++) // i+1 is used because we have to compare an element with the element after it
//		{
//			if (array[i] == array[j])
//			{
//				duplicate++;
//
//				// if duplicate found Shift all elements left to remove duplicate
//
//				for (int k = j; k < size - 1; k++)
//				{
//					array[k] = array[k + 1];
//					/* Yani jis index matlab  pr i match howa hum us index yaani j pr us index se agli value ko la rhe
//					 in this case on j-th index duplicate found i.e i-th and j-th index have same value
//					 i to wiase hi rhe ga magr j-th index pr hum j+1 index ki value le ain ge or isi tarah values shift */
//				}
//
//				size--; // reducing size
//				j--;
//				/* kio k j++ ho jay ag jaise hi nichli bracket pe pohnchen ge is se j aik index agle pr jay ga
//				 mgr hume check krn aha k kia ab jo value peeche ai wo kahin dupliacted to nhi ho rhi
//				 is liye hum ne j ko aik minus rk diya
//				 suppose j us time 2 tha or wo niche racjet me jane pr 3 hona tha mgr hum ne use aik kam kia jis se wo 1 ho gaya
//				 ab jab ye j neeche bracket pr jay ga to ye again ++ ho k 2 ban jay ga or again checking ho jay gi*/
//			}
//		}
//	}
//
//
//	// Showing Array without duplicates 
//	cout << "\nArray after removing duplicates: ";
//	for (int i = 0; i < size; i++)
//	{
//		cout << array[i] << " ";
//	}
//	cout << endl;
//
//	cout << "\nTotal duplicates found: " << duplicate << endl;
//
//
//	cout << endl;
//	system("pause");
//	return 0;
//}