//#include <iostream>
//using namespace std;
//
//void minSchedule(int time[], int num, int id[])
//{
//	for (int i = 0; i < num - 1; i++)
//	{
//		for (int j = i + 1; j < num; j++)
//		{
//			if (time[j] < time[i])
//			{
//				int temp = time[i];
//				time[i] = time[j];
//				time[j] = temp;
//
//				int tempId = id[i];   //swapping costumer ids
//				id[i] = id[j];
//				id[j] = tempId;
//			}
//		}
//	}
//
//	cout << "\nPrinting Order (Customer Numbers): ";
//	for (int i = 0; i < num; i++)
//	{
//		cout << "C" << id[i] << " ";
//	}
//	cout << endl;
//
//}
//
//int minimalWaitingTime(int time[], int num)
//{
//	int totalWait = 0;
//	int sumOfTime = 0;
//
//	for (int i = 0; i < num - 1; i++)
//	{
//		sumOfTime += time[i];
//		totalWait += sumOfTime;
//	}
//	return totalWait;
//}
//
//
//
//int main()
//{
//	int num;
//	int time[100];
//	int id[100];   // array for costumer id
//
//	do
//	{
//		cout << "Enter the Number of costumers: ";
//		cin >> num;
//
//		if (num <= 0)
//		{
//			cout << "Error: Number of costumers must be greater than 0!!" << endl;
//			cout << endl;
//		}
//	} while (num <= 0);
//
//	cout << "\nEnter job time for each customer: " << endl;
//
//	for (int i = 0; i < num; i++)
//	{
//		cout << "Job time for Costumer " << i + 1 << ": ";
//		cin >> time[i];
//		id[i] = i + 1;
//	}
//
//	minSchedule(time, num, id);
//
//	int total = minimalWaitingTime(time, num);
//
//	cout << "\nMinimal Total Waiting Time: " << total << endl;
//
//
//	cout << "\n" << endl;
//	system("pause");
//	return 0;
//}