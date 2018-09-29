#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int powerLinearTime(int number, int power);
int powerLogarithmicTime(int number, int power);
void testsPowerLinearTime();
void testsPowerLogarithmicTime();

int main()
{
	testsPowerLinearTime();
	testsPowerLogarithmicTime();

	return 0;
}

int powerLinearTime(int number, int power)
{
	int result = 1;
	for (int i = 0; i < power; ++i)
	{
		result *= number;
	}
	return result;
}

int powerLogarithmicTime(int number, int power)
{
	int result = 1;
	int temp = number;
	while (power)
	{
		if (power % 2 == 1)
		{
			result *= temp;
			temp *= temp;
		}
		else
		{
			temp *= temp;
		}
		power /= 2;
	}
	return result;
}

void testsPowerLinearTime()
{
	int const size = 3;
	int testNumbers[size]{ 7, 5, 2 };
	int testPowers[size]{ 1, 4, 12 };
	int testRightResults[size]{ 7, 625, 4096 };
	for (int i = 0; i < size; ++i)
	{
		if (powerLinearTime(testNumbers[i], testPowers[i]) == testRightResults[i])
		{
			printf("Test %i for linear time algorithm passed. Input(number, power): %i, %i. Output: %i\n",
				i + 1, testNumbers[i], testPowers[i], powerLinearTime(testNumbers[i], testPowers[i]));
		}
		else
		{
			printf("Test %i for linear time algorithm failed. Input(number, power): %i, %i. Output: %i\n", 
				i + 1, testNumbers[i], testPowers[i], powerLinearTime(testNumbers[i], testPowers[i]));
		}
	}
}

void testsPowerLogarithmicTime()
{
	int const size = 3;
	int testNumbers[size]{ 7, 5, 2 };
	int testPowers[size]{ 1, 4, 12 };
	int testRightResults[size]{ 7, 625, 4096 };
	for (int i = 0; i < size; ++i)
	{
		if (powerLogarithmicTime(testNumbers[i], testPowers[i]) == testRightResults[i])
		{
			printf("Test %i for logarithmic time algorithm passed. Input(number, power): %i, %i. Output: %i\n",
				i + 1, testNumbers[i], testPowers[i], powerLogarithmicTime(testNumbers[i], testPowers[i]));
		}
		else
		{
			printf("Test %i for logarithmic time algorithm failed. Input(number, power): %i, %i. Output: %i\n",
				i + 1, testNumbers[i], testPowers[i], powerLogarithmicTime(testNumbers[i], testPowers[i]));
		}
	}
}