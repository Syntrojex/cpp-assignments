//#include <iostream>
//using namespace std;
//
//void compressed(char str[], char compress[])
//{
//	int i = 0, j = 0;
//	while (str[i] != '\0')
//	{
//		char a = str[i];
//		int count = 0;
//
//		while (str[i] != '\0' && str[i] == a)
//		{
//			count++;
//			i++;
//		}
//		compress[j] = a;
//		j++;
//		if (count < 10)
//		{
//			compress[j] = count + '0';
//			j++;
//		}
//		else {
//			int temp = count, d = 0;
//			char n[100];
//			while (temp > 0)
//			{
//				n[d] = (temp % 10) + '0';
//				d++;
//				temp /= 10;
//			}
//
//			for (int k = d - 1; k >= 0; k--)
//			{
//				compress[j] = n[k];
//				j++;
//			}
//		}
//	}
//	compress[j] = '\0';
//	cout << "Compressed string: " << compress << endl;
//}
//
//void decompressed(char compress[], char decompress[])
//{
//	int i = 0, k = 0;
//	while (compress[i] != '\0')
//	{
//		char ch = compress[i];
//		i++;
//		int count = 0;
//
//		while (compress[i] >= '0' && compress[i] <= '9')
//		{
//			count = count * 10 + (compress[i] - '0');
//			i++;
//		}
//		for (int j = 0; j < count; j++)
//		{
//			decompress[k] = ch;
//			k++;
//		}
//	}
//	decompress[k] = '\0';
//	cout << "Decompressed string: " << decompress << endl;
//}
//
//int main()
//{
//	char str[100];
//	char compress[100];
//	char decompress[100];
//	cout << "Enter a string: ";
//	cin.getline(str, 100);
//
//	compressed(str, compress);
//	decompressed(compress, decompress);
//
//	return 0;
//}