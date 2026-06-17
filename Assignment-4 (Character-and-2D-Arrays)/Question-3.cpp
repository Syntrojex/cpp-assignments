#include <iostream>
using namespace std;

int getLength(char str[])
{
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return len;
}

bool matchAtPosition(char dataset[], char needle[], int datasetPos, int needleLen)
{
	for (int i = 0; i < needleLen; i++)
	{
		if (dataset[datasetPos + i] != needle[i])
		{
			return false;
		}
	}
	return true;
}

int findFrequency(char dataset[], char needle[])
{
	int datasetLen = getLength(dataset);
	int needleLen = getLength(needle);
	int frequency = 0;

	if (needleLen == 0 || needleLen > datasetLen)
	{
		return 0;
	}

	for (int i = 0; i <= datasetLen - needleLen; i++)
	{
		if (matchAtPosition(dataset, needle, i, needleLen))
		{
			frequency++;
		}
	}

	return frequency;
}

int main()
{
	char dataset[10000];
	char needle[1000];

	cout << "Enter Dataset text: ";
	cin.getline(dataset, 10000);

	cout << "Enter Needle text: ";
	cin.getline(needle, 1000);

	int frequency = findFrequency(dataset, needle);

	cout << "\nFrequency of needle in dataset: " << frequency << endl;

	return 0;
}