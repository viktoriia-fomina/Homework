#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

void tests();

int main()
{
	tests();

	return 0;
}

void tests()
{
	int const size1 = 4;
	int const size2 = 3;

	int test1[size1] = { 0, -2, 3, -9 };
	int test2[size2] = { 1, 1, 1 };

	int result1[size1] = { -9, -2, 0, 3 };
	int result2[size2] = { 1, 1, 1 };

	selectionSort(size1, test1);
	selectionSort(size2, test2);

	bool flagIfIsCorrect1 = true;
	bool flagIfIsCorrect2 = true;

	for (int i = 0; i < size1; ++i)
	{
		if (result1[i] != test1[i])
		{
			flagIfIsCorrect1 = false;
			break;
		}
	}
	if (flagIfIsCorrect1)
	{
		printf("Test 1 passed\n");
	}
	else
	{
		printf("Test 1 failed\n");
	}

	for (int i = 0; i < size2; ++i)
	{
		if (result2[i] != test2[i])
		{
			flagIfIsCorrect2 = false;
			break;
		}
	}
	if (flagIfIsCorrect2)
	{
		printf("Test 2 passed\n");
	}
	else
	{
		printf("Test 2 failed\n");
	}
}