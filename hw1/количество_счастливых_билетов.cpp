#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int const size = 28;
	int array[size]{};
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 10; ++k)
			{
				array[i + j + k]++;
			}
		}
	}
	int number = 0;
	for (int i = 0; i < size; ++i)
	{
		number += array[i] * array[i];
	}
	printf("%i\n", number);
	return 0;
}