#define _CRT_SECURE_NO_WARNINGS
#include "tests.h"
#include "Subscriber.h"
#include "Phonebook.h"
#include <stdio.h>

int tests()
{
	Subscriber s1("Ololo", "1234");
	Phonebook p;
	p.addNote(s1);
	p.saveToFile();
	FILE* file = fopen("phonebook.txt", "r");
	bool testPassed = false;
	int const size = 12;
	char str[size] = "Ololo 1234\n";
	if (!file)
	{
		printf("FILE WAS NOT FOUND\n");
		return -1;
	}
	char buffer[100]{};
	while (!feof(file))
	{
		char* str = fgets(buffer, 20, file);
		if (str == nullptr)
		{
			break;
		}
		for (int i = 0; i < size; ++i)
		{
			if (buffer[i] == str[i])
			{
				testPassed = true;
			}
			else
			{
				testPassed = false;
				break;
			}
		}
		if (testPassed)
		{
			printf("Tests passed. Saved to file successfully\n\n");
			break;
		}
	}
	if (!testPassed)
	{
		printf("Tests failed. Not saved to file successfully\n\n");
	}
	fclose(file);
	return 0;
}