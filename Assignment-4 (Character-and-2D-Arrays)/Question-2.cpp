//#include <iostream>
//using namespace std;
//
//int getLength(char str[])
//{
//	int len = 0;
//	while (str[len] != '\0')
//	{
//		len++;
//	}
//	return len;
//}
//
//int extractWords(char text[], char words[][100], int wordStarts[])
//{
//	int textLen = getLength(text);
//	int wordCount = 0;
//	int charIndex = 0;
//	int i = 0;
//
//	while (i < textLen)
//	{
//		while (i < textLen && text[i] == ' ')
//		{
//			i++;
//		}
//
//		if (i < textLen)
//		{
//			wordStarts[wordCount] = i;
//			charIndex = 0;
//
//			while (i < textLen && text[i] != ' ')
//			{
//				words[wordCount][charIndex] = text[i];
//				charIndex++;
//				i++;
//			}
//			words[wordCount][charIndex] = '\0';
//			wordCount++;
//		}
//	}
//
//	return wordCount;
//}
//
//bool matchPattern(char word[], char pattern[], int wordPos, int patternPos)
//{
//	int wordLen = getLength(word);
//	int patternLen = getLength(pattern);
//
//	if (patternPos == patternLen && wordPos == wordLen)
//	{
//		return true;
//	}
//
//	if (patternPos == patternLen)
//	{
//		return false;
//	}
//
//	if (wordPos == wordLen)
//	{
//		for (int i = patternPos; i < patternLen; i++)
//		{
//			if (pattern[i] != '*')
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//
//	if (pattern[patternPos] == '?')
//	{
//		return matchPattern(word, pattern, wordPos + 1, patternPos + 1);
//	}
//
//	if (pattern[patternPos] == '*')
//	{
//		if (matchPattern(word, pattern, wordPos, patternPos + 1))
//		{
//			return true;
//		}
//
//		for (int i = wordPos; i < wordLen; i++)
//		{
//			if (matchPattern(word, pattern, i + 1, patternPos + 1))
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//
//	if (word[wordPos] == pattern[patternPos])
//	{
//		return matchPattern(word, pattern, wordPos + 1, patternPos + 1);
//	}
//
//	return false;
//}
//
//void findMatches(char text[], char pattern[])
//{
//	char words[100][100];
//	int wordStarts[100];
//	int indices[100];
//	int count = 0;
//
//	int wordCount = extractWords(text, words, wordStarts);
//
//	for (int i = 0; i < wordCount; i++)
//	{
//		if (matchPattern(words[i], pattern, 0, 0))
//		{
//			indices[count] = wordStarts[i];
//			count++;
//		}
//	}
//
//	if (count == 0)
//	{
//		cout << "No matches found." << endl;
//	}
//	else
//	{
//		cout << "Answer is= ";
//		for (int i = 0; i < count; i++)
//		{
//			cout << indices[i];
//			if (i < count - 1)
//			{
//				cout << ", ";
//			}
//		}
//		cout << endl;
//	}
//}
//
//int main()
//{
//	char text[1000];
//	char pattern[100];
//
//	cout << "Enter text: ";
//	cin.getline(text, 1000);
//
//	cout << "Enter pattern (use ? for single character, * for multiple): ";
//	cin.getline(pattern, 100);
//
//	findMatches(text, pattern);
//
//	return 0;
//}