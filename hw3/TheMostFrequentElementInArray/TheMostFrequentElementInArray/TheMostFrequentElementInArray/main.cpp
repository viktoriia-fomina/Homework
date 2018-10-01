#include "Header.h"

void mostFrequentElementTests();

int main()
{
	mostFrequentElementTests();

	return 0;
}

void mostFrequentElementTests()
{
	// 3 массива для трех тестов
	int const size1 = 4;
	int array1[size1] = { 1, 3, 3, 4 };
	int const size2 = 7;
	int array2[size2] = { 4, 5, 7, 0,-7 ,8 ,5 };
	int const size3 = 9;
	int array3[size3] = { 6, 6, 9, 0, 3, 9, 4, 9, 9 };

	int const result1 = mostFrequentElement(size1, array1);
	if (result1 == 3)
	{
		printf("Test 1 passed\n");
	}
	else
	{
		printf("Test 1 failed with result %i\n", result1);
	}

	int const result2 = mostFrequentElement(size2, array2);
	if (result2 == 5)
	{
		printf("Test 2 passed\n");
	}
	else
	{
		printf("Test 2 failed with result %i\n", result2);

	}

	int const result3 = mostFrequentElement(size3, array3);
	if (result3 == 9)
	{
		printf("Test 3 passed\n");
	}
	else
	{
		printf("Test 3 failed\n with result %i\n", result3);
	}
}