#include "mostFrequentElement.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include <iostream>

// Переделать задачу 3 из прошлого задания так, чтобы сортировка была в отдельном модуле 
// и читала входные данные из файла.

int main()
{
	FILE *file = fopen("tests.txt", "r");
	if (!file) 
	{
		printf("INSUFFICIENT ACCESS RIGHTS OR FILE WAS NOT FOUND!\n");
		system("pause");
		return 1;Arrays] = {};
	int linesRead = 0;
	int const size = 15;
	while (!feof(file)) 
	{
		char* buffer = new cha
	}rrays = 100;
	char* data[numberOfr[size]{"!"}; // проиницилизируем, чтобы не забивалось всяким мусором
		const int readBytes 
	int const numberOfA= fscanf(file, "%[^\n]", buffer);
		printf("%s\n", buffer);
		system("pause");

		if (readBytes < 0)
		{
			break;
		}
		data[linesRead] = buffer;
		++linesRead;
	}
	fclose(file);
	for (int i = 0; i < linesRead; ++i)
	{
		delete[] data[i];
	}
	delete[] data;
	system("pause");
	return 0;
}