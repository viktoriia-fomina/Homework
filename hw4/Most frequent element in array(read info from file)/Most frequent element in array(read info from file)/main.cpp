#include "mostFrequentElement.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include <iostream>

// Переделать задачу 3 из прошлого задания так, чтобы сортировка была в отдельном модуле 
// и читала входные данные из файла.

int parser(int* numbers, char const * string);

int main()
{
	FILE* file = fopen("tests.txt", "r");
	if (file == nullptr)
	{
		perror("ERROR OPENING FILE\n");
	}
	else
	{
		int const size = 100;
		char* string = new char[size];
		while (!feof(file))
		{
			fgets(string, size, file);
			int* numbers = new int[size];
			int sizeOfArray = parser(numbers, string);
			for (int i = 0; i < sizeOfArray; ++i)
			{
				printf("%i ", numbers[i]);
			}
			printf("\n");
			delete[] numbers;
		}
		delete[] string;
	}

	system("pause");
	return 0;
}

int parser(int* numbers, char const * string)
{
	int const sizeOfTemp = 100;
	char* temp = new char[sizeOfTemp];
	int size = 0;
	int iterator = 0;
	while (string[iterator] != '\0')
	{
		int j = 0;
		bool flag = false;
		while (string[iterator] != ' ' && string[iterator] != '\n' && string[iterator] != '\0')
		{
			temp[j] = string[iterator];
			++j;
			++iterator;
			flag = true;
		}
		if (flag)
		{
			temp[j] = '\0';
			numbers[size] = atoi(temp);
			++size;
		}
		else
		{
			++iterator;
		}
	}
	delete[] temp;
	return size;
}