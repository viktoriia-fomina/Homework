#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int &a, int &b);
void bubbleSort(int size, int* array);
void convertArray(int size, int* array);
bool ifConditionFullfilled(int size, int firstElement, int* array);
void testsCheckAlgorithmWorksRight(int rows, int cols[], int firstElements[],
	int** testArrays, int** testArraysCopy);
void testsConvertArray();

int main()
{
	testsConvertArray();

	return 0;
}

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

void bubbleSort(int size, int* array)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = size - 1; j > i; --j)
		{
			if (array[j] < array[j - 1])
			{
				swap(array[j], array[j - 1]);
			}
		}
	}
}

void convertArray(int size, int* array)
{
	int addressFirst = 0;
	int first = array[0];
	for (int i = 0; i < size; ++i)
	{
		if (array[i] < first)
		{
			if (i - addressFirst == 1)
			{
				swap(array[addressFirst], array[addressFirst + 1]);
				addressFirst++;
			}
			else
			{
				swap(array[i], array[addressFirst + 1]);
				swap(array[addressFirst], array[addressFirst + 1]);
				addressFirst++;
			}
		}
	}
}

bool ifConditionFullfilled(int size, int firstElement, int* array)
{
	bool ifAlgorithmFullfillsTheCondition = true;
	int count = 0;
	while (array[count] < firstElement && count < size)
	{
		count++;
	}
	while (array[count] == firstElement && count < size)
	{
		count++;
	}
	while (array[count] > firstElement && count < size)
	{
		count++;
	}
	if (count != size)
	{
		ifAlgorithmFullfillsTheCondition = false;
	}
	return ifAlgorithmFullfillsTheCondition;
}

void testsCheckAlgorithmWorksRight(int rows, int cols[], int firstElements[],
	int** testArrays, int** testArraysCopy)
{
	bool* ifAlgorithmIsRight = new bool[rows] { true, true, true };
	for (int i = 0; i < rows; ++i)
	{
		ifAlgorithmIsRight[i] = ifConditionFullfilled(cols[i], firstElements[i], testArrays[i]);
	}
	for (int i = 0; i < rows; ++i)
	{
		bubbleSort(cols[i], testArrays[i]);
		bubbleSort(cols[i], testArraysCopy[i]);
	}
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols[i]; ++j)
		{
			if (testArrays[i][j] != testArraysCopy[i][j])
			{
				ifAlgorithmIsRight[i] = false;
			}
		}
	}
	for (int i = 0; i < rows; ++i)
	{
		if (ifAlgorithmIsRight[i])
		{
			printf("Test %i passed\n", i + 1);
		}
		else
		{
			printf("Test %i failed\n", i + 1);
		}
	}
	delete[] ifAlgorithmIsRight;
}

void testsConvertArray()
{
	int const rows = 3;
	int cols[rows] = { 4, 7, 9 };
	int firstElements[rows]{}; // сюда запишем первые элементы каждого из 3 массивов
							   // выделение памяти под массив из 3 массивов (к этим массивам применим наш алгоритм)
	int** testArrays = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		testArrays[i] = new int[cols[i]];
	}
	// выделение памяти под копию массива из 3 массивов 
	// (нужен, чтобы проверить, что алгоритм не только выполняет условие, но и не портит значения)
	int** testArraysCopy = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		testArraysCopy[i] = new int[cols[i]];
	}
	// заполнение массива случайными числами (для удобства сужен диапазон), заполнение копии
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols[i]; ++j)
		{
			testArrays[i][j] = rand() % 100 - 50;
			testArraysCopy[i][j] = testArrays[i][j];
		}
	}
	// запоминаем первый элемент каждого из массивов
	for (int i = 0; i < rows; ++i)
	{
		firstElements[i] = testArrays[i][0];
	}
	// выводим данные, на которых тестируем
	for (int i = 0; i < rows; ++i)
	{
		printf("Input for test %i :\n", i + 1);
		for (int j = 0; j < cols[i]; ++j)
		{
			printf("%i ", testArrays[i][j]);
		}
		printf("\n");
	}
	// применяем алгоритм ко всем 3 массивам
	for (int i = 0; i < rows; ++i)
	{
		convertArray(cols[i], testArrays[i]);
	}
	// выводим результат работы алгоритма
	for (int i = 0; i < rows; ++i)
	{
		printf("Test %i output:\n", i + 1);
		for (int j = 0; j < cols[i]; ++j)
		{
			printf("%i ", testArrays[i][j]);
		}
		printf("\n");
	}
	// проверим, условие (в начале массивов элементы меньшие первого, а в конце - большие) и
	// что алгоритм не портит массивы (для этого отсортируем 3 массива, 
	// их копии и сравним массивы с копиями) 
	// выведем результат теста
	testsCheckAlgorithmWorksRight(rows, cols, firstElements, testArrays, testArraysCopy);
	// освобождение памяти
	for (int i = 0; i < rows; ++i)
	{
		delete[] testArrays[i];
		delete[] testArraysCopy[i];
	}
	delete[] testArrays;
	delete[] testArraysCopy;
}