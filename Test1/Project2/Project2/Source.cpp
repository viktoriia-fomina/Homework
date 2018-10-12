#include "Header.h"
#include <math.h>
#include <stdio.h>

// Два неотрицательных числа заданы в двоичной форме в массивах.
// Элементы обоих массивов - булевые.Написать программу, которая определяет, какое число больше.

int toDecimal(int size, int* array);
void toBinary(int size, bool* array, int* arr);

void whichNumberISGrander(int size1, bool* array1, int size2, bool* array2)
{
	int* arr1 = new int[size1];
	int* arr2 = new int[size2];
	
	toBinary(size1, array1, arr1);
	toBinary(size2, array2, arr2);

	int const number1 = toDecimal(size1, arr1);
	int const number2 = toDecimal(size2, arr2);

	if (number1 > number2)
	{
		printf("First number is grander\n");
	}
	else if (number1 == number2)
	{
		printf("Numbers are the same\n");
	}
	else
	{
		printf("Second number is grander\n");
	}

	delete arr1;
	delete arr2;
}

int toDecimal(int size, int* array)
{
	int number = 0;
	for (int i = 0; i < size; ++i)
	{
		number += array[size - i - 1] * (int)(pow(2, i));
	}
	return number;
}

void toBinary(int size, bool* array, int* arr)
{
	for (int i = 0; i < size; ++i)
	{
		if (array[i])
		{
			arr[i] = 1;
		}
		else
		{
			arr[i] = 0;
		}
	}
}