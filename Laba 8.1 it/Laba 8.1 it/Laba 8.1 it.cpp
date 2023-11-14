#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool Find(char* str)
{
	int i = 0;
	size_t len = strlen(str);
	while (i < len && str[i + 1] != 0)
	{
		if (str[i] == 'n' && str[i + 1] == 'o')
		{
			return true;
		}
		else if(str[i] == 'o' && str[i + 1] == 'n')
		{
			return true;
		}
		i++;
	}
	return false;
}

char* Change(char* str)
{
	size_t len = strlen(str);
	char* tmp = new char[len * 4 / 3 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	size_t i = 0;

	while (i < len && str[i + 1] != 0)
	{
		if (str[i] == 'n' && str[i + 1] == 'o')
		{
			strcat(t, "***");
			t += 3;
			i += 2;
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
		}
	}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy(str, tmp);
	return tmp;
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	cout << "String contains no or on: " << boolalpha << Find(str) << endl;

	char* dest = new char[151];
	dest = Change(str);
	cout << "Param:  " << str << endl;
	cout << "Result: " << dest << endl;

	return 0;
}