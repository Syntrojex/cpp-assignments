#include<iostream>
using namespace std;
int main()
{
	char input;
	cout << "Enter a Character: ";
	cin >> input;

	if (input >= '0' && input <= '9')
	{
		cout << "Number" << endl;
	}

	else if (input >= 'A' && input <= 'Z')
	{
		cout << "Upper-case Alphabet" << endl;
	}

	else if (input >= 'a' && input <= 'z')
	{
		cout << "Lower-case Alphabet" << endl;
	}

	else if (input == ',' || input == '.' || input == '?' || input == '"' || input == '\'' || input == ';' || input == ':' || input == '`')
	{
		cout << "Punctuation Mark" << endl;
	}

	else if (input == '(' || input == ')' || input == '[' || input == ']' || input == '{' || input == '}')
	{
		cout << "Brackets/Parenthesis" << endl;
	}

	else if (input == char(32))
	{
		cout << "Space" << endl;
	}

	else if (input == '_' || input == '-' || input == '+' || input == '*' || input == '&' || input == '^' || input == '%' || input == '$' || input == '#' || input == '@' || input == '!' || input == '~' || input == '<' || input == '>' || input == '/' || input == '\\')
	{
		cout << "Symbol" << endl;
	}

	else
	{
		cout << "Special Character" << endl;
	}

	system("pause");
	return 0;
}
