//#include <iostream>
//using namespace std;
//
//void encryption(char text[], char key[], char encrypt[])
//{
//	int i = 0, j = 0;
//	while (text[i] != '\0')
//	{
//		char t = text[i];
//		char k = key[j];
//		encrypt[i] = ((t + k) % 95);
//		i++;
//		j++;
//		if (key[j] == '\0')
//		{
//			j = 0;
//		}
//	}
//	encrypt[i] = '\0';
//	cout << "Encrypted text:" << endl << encrypt << endl;
//}
//
//void decryption(char encrypt[], char key[], char decrypt[])
//{
//	int i = 0, j = 0;
//	while (encrypt[i] != '\0')
//	{
//		char e = encrypt[i];
//		char k = key[j];
//		decrypt[i] = ((e - k + 95) % 95);
//		i++;
//		j++;
//		if (key[j] == '\0')
//		{
//			j = 0;
//		}
//	}
//	decrypt[i] = '\0';
//	cout << "Decrypted text:" << endl << decrypt << endl;
//}
//
//int main()
//{
//	char key[100];
//	char encrypt[100];
//	char decrypt[100];
//	char text[100];
//
//	cout << "Enter your text: ";
//	cin.getline(text, 100);
//
//	cout << "Enter key: ";
//	cin.getline(key, 100);
//
//	encryption(text, key, encrypt);
//	decryption(encrypt, key, decrypt);
//
//	return 0;
//}