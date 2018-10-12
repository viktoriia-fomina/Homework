//Дан файл, содержащий в себе целые числа, записанные через пробел.
//Написать программу, разворачивающую порядок чисел в этом файле
//(например, если в исходном файле было "1 2 3", в нём же должно оказаться "3 2 1").
//Известно, что чисел в файле не более 100.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* file;
	char** string = new char*[100];
	file = fopen("text.txt", "r");
	int i = 0;
	while (!feof(file))
	{
		string[i] = new char[10];
		fscanf(file, "%s", string[i]);
		++i;
	}
	fclose(file);
	FILE * file2 = fopen("text.txt", "w");
	for (int k = i - 1; k >= 0; --k)
	{
		fwrite(string[k], sizeof(char), strlen(string[k]), file2);
		fwrite(" ", sizeof(char), 1, file2);
	}
	fclose(file2);
	return 0;
}