#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("Input size of array : ");
	int size = 0;
	scanf("%i", &size);
	int* array = new int[size];
	printf("Input elements of array\n");
	int count = 0;
	for (int i = 0; i < size; ++i)
	{
		scanf("%i", &array[i]);
	}
	for (int i = 0; i < size; ++i)
	{
		if (array[i] == 0)
		{
			count++;
		}
	}
	printf("In array %i elements equal to zero\n", count);
	delete[] array;
	return 0;
}