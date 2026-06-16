//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//// i have done it global so that we have to only change the values of the given 4 variables and automatically all values will be changed
//const int rowA = 3;
//const int columnA = 3;
//const int rowB = 3;
//const int columnB = 3;
//
//void display_matrices(int matA[][columnA], int rowA, int columnA, int matB[][columnB], int rowB, int columnB)
//{
//	cout << "\nMatrix-A and Matrix-B: " << endl;
//
//	int maxRows;
//	if (rowA > rowB)
//	{
//		maxRows = rowA;
//	}
//	else
//	{
//		maxRows = rowB;
//	}
//
//	for (int i = 0; i < maxRows; i++)
//	{
//		if (i < rowA)
//		{
//			cout << "{";
//			for (int j = 0; j < columnA; j++)
//			{
//				cout << setw(4) << matA[i][j];
//			}
//			cout << "}";
//		}
//		else
//		{
//			for (int s = 0; s < (columnA * 4) + 2; s++)  //*4 is used because setw(4) use kia or +2 is liye kio har bracket { ye wali lagni 2 har row me 
//			{
//				cout << " ";
//			}
//		}
//
//		cout << "        "; // to print gap between both matrices
//		if (i < rowB)
//		{
//			cout << "{";
//			for (int j = 0; j < columnB; j++)
//			{
//				cout << setw(4) << matB[i][j];
//			}
//			cout << "}";
//		}
//		cout << endl;
//	}
//
//}
//void product(int matA[][columnA], int rowA, int columnA, int matB[][columnB], int rowB, int columnB, int result[][10])
//{
//	if (columnA != rowB)
//	{
//		cout << "Error: Matrix multiplication is not possible!!" << endl;
//		return;
//	}
//
//	for (int i = 0; i < rowA; ++i)
//	{
//		for (int j = 0; j < columnB; ++j)
//		{
//			result[i][j] = 0;
//		}
//	}
//
//	for (int i = 0; i < rowA; i++)
//	{
//		for (int j = 0; j < columnB; j++)
//		{
//			for (int m = 0; m < columnA; m++)
//			{
//				result[i][j] += matA[i][m] * matB[m][j];
//			}
//		}
//	}
//
//	cout << "\nMultiplication (Matrix-A-Matrix-B): " << endl;
//	for (int i = 0; i < rowA; i++)
//	{
//		cout << "{";
//		for (int j = 0; j < columnB; j++)
//		{
//			cout << setw(4) << result[i][j];
//		}
//		cout << "}" << endl;
//	}
//}
//
//
//void addition(int matA[][columnA], int rowA, int columnA, int matB[][columnB], int rowB, int columnB)
//{
//	// we know that matrices can only be added if their order is same
//	if (rowA == rowB && columnA == columnB)
//	{
//		int resultant[10][10];
//		for (int i = 0; i < rowA; i++)
//		{
//			for (int j = 0; j < columnA; j++)
//			{
//				resultant[i][j] = matA[i][j] + matB[i][j];
//			}
//		}
//		int resultant_rows = rowA;
//		int resultant_columns = columnA;
//
//		cout << "\nAddition (Matrix-A+Matrix-B): " << endl;
//		for (int i = 0; i < resultant_rows; i++)
//		{
//			cout << "{";
//			for (int j = 0; j < resultant_columns; j++)
//			{
//				cout << setw(4) << resultant[i][j];
//			}
//			cout << "}" << endl;
//		}
//	}
//	else
//	{
//		cout << "Matrices cannot be added(Because order of both matrices is not same)!!" << endl;
//		cout << endl;
//	}
//}
//
//void subtraction(int matA[][columnA], int rowA, int columnA, int matB[][columnB], int rowB, int columnB)
//{
//	// we know that matrices can only be subtracted if their order is same
//	if (rowA == rowB && columnA == columnB)
//	{
//		int resultant[10][10];
//		for (int i = 0; i < rowA; i++)
//		{
//			for (int j = 0; j < columnA; j++)
//			{
//				resultant[i][j] = matA[i][j] - matB[i][j];
//			}
//		}
//		int resultant_rows = rowA;
//		int resultant_columns = columnA;
//
//		cout << "\nSubtraction (Matrix-A-Matrix-B): " << endl;
//		for (int i = 0; i < resultant_rows; i++)
//		{
//			cout << "{";
//			for (int j = 0; j < resultant_columns; j++)
//			{
//				cout << setw(4) << resultant[i][j];
//			}
//			cout << "}" << endl;
//		}
//	}
//	else
//	{
//		cout << "Matrices cannot be subtracted(Because order of both matrices is not same)!!" << endl;
//		cout << endl;
//	}
//}
//
//void determinantA(int matA[][columnA], int rowA, int columnA)
//{
//	if (rowA == columnA)
//	{
//		if (rowA == 1 && columnA == 1)
//		{
//			int determinant = matA[0][0];
//			cout << "\nDeterminant of Matrix-A: " << determinant << endl;
//		}
//		else if (rowA == 2 && columnA == 2)
//		{
//			int determinant = (matA[0][0] * matA[1][1]) - (matA[0][1] * matA[1][0]);
//			cout << "\nDeterminant of Matrix-A: " << determinant << endl;
//		}
//		else if (rowA == 3 && columnA == 3)
//		{
//			int determinant = (matA[0][0] * (matA[1][1] * matA[2][2] - matA[1][2] * matA[2][1])) - (matA[0][1] * (matA[1][0] * matA[2][2] - matA[1][2] * matA[2][0])) + (matA[0][2] * (matA[1][0] * matA[2][1] - matA[1][1] * matA[2][0]));
//			cout << "\nDeterminant of Matrix-A: " << determinant << endl;
//		}
//	}
//	else
//	{
//		cout << "\nError: Determinant is only possible for square matrices!" << endl;
//	}
//}
//
//void determinantB(int matB[][columnB], int rowB, int columnB)
//{
//	if (rowB == columnB)
//	{
//		if (rowB == 1 && columnB == 1)
//		{
//			int determinant = matB[0][0];
//			cout << "\nDeterminant of Matrix-B: " << determinant << endl;
//		}
//		else if (rowB == 2 && columnB == 2)
//		{
//			int determinant = (matB[0][0] * matB[1][1]) - (matB[0][1] * matB[1][0]);
//			cout << "\nDeterminant of Matrix-B: " << determinant << endl;
//		}
//		else if (rowB == 3 && columnB == 3)
//		{
//			int determinant = (matB[0][0] * (matB[1][1] * matB[2][2] - matB[1][2] * matB[2][1])) - (matB[0][1] * (matB[1][0] * matB[2][2] - matB[1][2] * matB[2][0])) + (matB[0][2] * (matB[1][0] * matB[2][1] - matB[1][1] * matB[2][0]));
//			cout << "\nDeterminant of Matrix-B: " << determinant << endl;
//		}
//	}
//	else
//	{
//		cout << "\nError: Determinant is only possible for square matrices!" << endl;
//	}
//}
//
//void sorting(int matA[][columnA], int rowA, int columnA, int matB[][columnB], int rowB, int columnB)
//{
//	// sorting matrix-A
//	int tempA[9];
//	int k1 = 0;
//	for (int i = 0; i < rowA; i++)
//	{
//		for (int j = 0; j < columnA; j++)
//		{
//			tempA[k1] = matA[i][j];
//			k1++;
//		}
//	}
//	// applying bubble sort algorithm
//	for (int i = 0; i < k1; i++)
//	{
//		for (int j = i + 1; j < k1; j++)
//		{
//			if (tempA[i] > tempA[j])
//			{
//				int temp1 = tempA[i];
//				tempA[i] = tempA[j];
//				tempA[j] = temp1;
//			}
//		}
//	}
//	int x = 0;
//	for (int i = 0; i < rowA; i++)
//	{
//		for (int j = 0; j < columnA; j++)
//		{
//			matA[i][j] = tempA[x];
//			x++;
//		}
//	}
//	cout << "\nSorted Matrix-A: " << endl;
//	for (int i = 0; i < rowA; i++)
//	{
//		cout << "{";
//		for (int j = 0; j < columnA; j++)
//		{
//			cout << setw(4) << matA[i][j];
//		}
//		cout << "}" << endl;
//	}
//
//	// sorting matrix-B
//	int tempB[9];
//	int k2 = 0;
//	for (int i = 0; i < rowB; i++)
//	{
//		for (int j = 0; j < columnB; j++)
//		{
//			tempB[k2] = matB[i][j];
//			k2++;
//		}
//	}
//	// applying bubble sort algorithm
//	for (int i = 0; i < k2; i++)
//	{
//		for (int j = i + 1; j < k2; j++)
//		{
//			if (tempB[i] > tempB[j])
//			{
//				int temp2 = tempB[i];
//				tempB[i] = tempB[j];
//				tempB[j] = temp2;
//			}
//		}
//	}
//	int y = 0;
//	for (int i = 0; i < rowB; i++)
//	{
//		for (int j = 0; j < columnB; j++)
//		{
//			matB[i][j] = tempB[y];
//			y++;
//		}
//	}
//	cout << "\nSorted Matrix-B: " << endl;
//	for (int i = 0; i < rowB; i++)
//	{
//		cout << "{";
//		for (int j = 0; j < columnB; j++)
//		{
//			cout << setw(4) << matB[i][j];
//		}
//		cout << "}" << endl;
//	}
//}
//
//int main()
//{
//	int matrixA[rowA][columnA];
//	int matrixB[rowB][columnB];
//
//	cout << "Enter values in MATRIX-A-->Order[" << rowA << "x" << columnA << "]" << endl;
//	for (int i = 0; i < rowA; i++)
//	{
//		for (int j = 0; j < columnA; j++)
//		{
//			cout << "Enter [" << i << "][" << j << "]: ";
//			cin >> matrixA[i][j];
//		}
//	}
//
//	cout << "\nEnter values in MATRIX-B-->Order[" << rowB << "x" << columnB << "]" << endl;
//	for (int i = 0; i < rowB; i++)
//	{
//		for (int j = 0; j < columnB; j++)
//		{
//			cout << "Enter [" << i << "][" << j << "]: ";
//			cin >> matrixB[i][j];
//		}
//	}
//	int result[10][10];
//
//	display_matrices(matrixA, rowA, columnA, matrixB, rowB, columnB);
//	product(matrixA, rowA, columnA, matrixB, rowB, columnB, result);
//	addition(matrixA, rowA, columnA, matrixB, rowB, columnB);
//	subtraction(matrixA, rowA, columnA, matrixB, rowB, columnB);
//	determinantA(matrixA, rowA, columnA);
//	determinantB(matrixB, rowB, columnB);
//	sorting(matrixA, rowA, columnA, matrixB, rowB, columnB);
//
//	cout << "\n" << endl;
//	system("pause");
//	return 0;
//}