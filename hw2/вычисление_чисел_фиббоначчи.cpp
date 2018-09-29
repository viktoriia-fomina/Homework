#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recursivelyFibbo(int number);
int iterativelyFibbo(int number);
void testsRecursivelyFibbo();
void testsIterativelyFibbo();

int main()
{
	testsRecursivelyFibbo();
	testsIterativelyFibbo();

	return 0;
}

int recursivelyFibbo(int number)
{
	if (number == 1 || number == 2)
	{
		return 1;
	}
	return recursivelyFibbo(number - 1) + recursivelyFibbo(number - 2);
}

int iterativelyFibbo(int number)
{
	int previous1 = 1;
	int previous2 = 1;
	int num = 2;

	if (number == 1 || number == 2)
	{
		return 1;
	}
	for (int i = 0; i < number - 3; ++i)
	{
		previous2 = previous1;
		previous1 = num;
		num = previous1 + previous2;
	}
	return num;
}

void testsRecursivelyFibbo()
{
	int const size = 3;
	int testNumbers[size] { 1, 9, 37 };
	int testRightResults[size]{ 1, 34, 24157817 };
	for (int i = 0; i < size; ++i)
	{
		if (recursivelyFibbo(testNumbers[i]) == testRightResults[i])
		{
			printf("Test %i for recursion passed. Input: %i. Output: %i\n", i + 1,
				testNumbers[i], recursivelyFibbo(testNumbers[i]));
		}
		else
		{
			printf("Test %i for recursion failed. Input: %i. Output: %i\n", i + 1, 
				testNumbers[i], recursivelyFibbo(testNumbers[i]));
		}
	}
}

void testsIterativelyFibbo()
{
	int const size = 3;
	int testNumbers[size]{ 1, 9, 37 };
	int testRightResults[size]{ 1, 34, 24157817 };
	for (int i = 0; i < size; ++i)
	{
		if (iterativelyFibbo(testNumbers[i]) == testRightResults[i])
		{
			printf("Test %i for iterative algorithm passed. Input: %i. Output: %i\n", i + 1,
				testNumbers[i], iterativelyFibbo(testNumbers[i]));
		}
		else
		{
			printf("Test %i for iterative algorithm failed. Input: %i. Output: %i\n", i + 1,
				testNumbers[i], iterativelyFibbo(testNumbers[i]));
		}
	}
}