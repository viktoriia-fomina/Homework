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
		return 1;
	}
	int* data[100] = {};
	int linesRead = 0;
	while (!feof(file)) 
	{
		int* buffer = new int[100];
		const int readBytes = fscanf(file, "%[^\n]", buffer);
		int size = strlen(buffer);
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
	system("pause");
	return 0;
}