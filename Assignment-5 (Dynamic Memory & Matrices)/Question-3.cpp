//#include<iostream>
//using namespace std;
//
//void input(int** arr, int rows, int cols)
//{
//	cout << "\nEnter Values in [" << rows << " X " << cols << "] matrix" << endl;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			cout << "Enter [" << i << "][" << j << "]: ";
//			cin >> *(*(arr + i) + j);
//		}
//	}
//}
//
//void display(int** arr, int rows, int cols)
//{
//	cout << "\nEntered Grid is: " << endl;
//	for (int i = 0; i < rows; i++)
//	{
//		cout << "{";
//		for (int j = 0; j < cols; j++)
//		{
//			cout << *(*(arr + i) + j);
//
//			if (j != cols - 1)
//			{
//				cout << ", ";
//			}
//		}
//		cout << "}" << endl;
//	}
//}
//
//void count(int** grid, int* arr, int rows, int cols)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			if (*(*(grid + i) + j) != 0)
//			{
//				arr[i]++;
//			}
//		}
//	}
//}
//
//void copyCompact(int** compact, int** grid, int rows, int cols)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		int index = 0;
//		for (int j = 0; j < cols; j++)
//		{
//			if (*(*(grid + i) + j) != 0)
//			{
//				*(*(compact + i) + index) = *(*(grid + i) + j);
//				index++;
//			}
//		}
//	}
//}
//
//void displayCompact(int** arr, int* rowCount, int rows)
//{
//	cout << "\nCompact Jagged Array:" << endl;
//	for (int i = 0; i < rows; i++)
//	{
//		cout << "{";
//		for (int j = 0; j < rowCount[i]; j++)
//		{
//			cout << *(*(arr + i) + j);
//
//			if (j != rowCount[i] - 1)
//			{
//				cout << ", ";
//			}
//		}
//		cout << "}" << endl;
//	}
//}
//
//int main()
//{
//	int cols;
//	int rows;
//
//	// Input Validity
//	do
//	{
//		cout << "Enter Number of Rows: ";
//		cin >> rows;
//
//		if (rows <= 0)
//		{
//			cout << "ERROR: Row Size must be greater than 0!!" << endl;
//			cout << endl;
//		}
//	} while (rows <= 0);
//
//	do
//	{
//		cout << "Enter Number of Columns: ";
//		cin >> cols;
//
//		if (cols <= 0)
//		{
//			cout << "ERROR: Column Size must be greater than 0!!" << endl;
//			cout << endl;
//		}
//	} while (cols <= 0);
//
//	// Making 2D array Dynamically
//	int** grid = new int* [rows];
//	for (int i = 0; i < rows; i++)
//	{
//		*(grid + i) = new int[cols];
//	}
//
//	// Getting user Input
//	input(grid, rows, cols);
//
//	// Displaying the Entered Array
//	display(grid, rows, cols);
//
//	// Making 1D array to store size of each row with nonzero elements
//	int* rowCount = new int[rows];
//
//	// Initializing all the array with 0
//	for (int i = 0; i < rows; i++)
//	{
//		rowCount[i] = 0;
//	}
//
//	// Counting Non zero elements in every row
//	count(grid, rowCount, rows, cols);
//
//	// making Compact Array
//	int** compact = new int* [rows];
//	for (int i = 0; i < rows; i++)
//	{
//		compact[i] = new int[rowCount[i]];
//	}
//
//	// Copying Elements
//	copyCompact(compact, grid, rows, cols);
//
//	// Display Compact array
//	displayCompact(compact, rowCount, rows);
//
//	// Clearing the Memory
//
//	for (int i = 0; i < rows; i++)
//	{
//		delete[] * (grid + i);
//	}
//
//	delete[] grid;
//	grid = nullptr;
//
//	delete[] rowCount;
//	rowCount = nullptr;
//
//	for (int i = 0; i < rows; i++)
//	{
//		delete[] compact[i];
//	}
//	delete[] compact;
//	compact = nullptr;
//
//	cout << "\n" << endl;
//	system("pause");
//	return 0;
//}