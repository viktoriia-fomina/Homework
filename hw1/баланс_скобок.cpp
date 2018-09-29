#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool balance(int size, char* string);

int main()
{
	int size = 0;
	printf("Input size of string : ");
	scanf("%i", &size);
	char* string = new char[size + 1];
	printf("Input string\n");
	scanf("%s", string);
	string[size] = '\0';

	if (balance(size, string))
	{
		printf("OK\n");
	}
	else
	{
		printf("Not OK \n");
	}

	delete[] string;
	return 0;
}

bool balance(int size, char* string)
{
	int count = 0;
	bool flag = true;

	for (int i = 0; i < size; ++i)
	{
		if (string[i] == ')' && count <= 0)
		{
			flag = false;
			break;
		}
		if (string[i] == ')' && count > 0)
		{
			count--;
		}
		if (string[i] == '(')
		{
			count++;
		}
	}
	if (count != 0)
	{
		flag = false;
	}
	return flag;
}