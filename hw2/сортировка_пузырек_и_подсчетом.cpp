#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

void swap(int &a, int &b);
void bubbleSort(int size, int* array);
void countingSort(int size, int* array);
int compIncrease(const void* a, const void* b);
void testsCompareArrayAndCopy(int rows, int cols[], int** testArrays, int** testArraysCopy);
void testsPrintInput(int rows, int cols[], int** testArrays);
void testsBubbleAndCountingSorts();

int main()
{
	testsBubbleAndCountingSorts();
	
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

void countingSort(int size, int* array)
{
	int min = array[0];
	int max = array[0];
	int count = 0;
	for (int i = 1; i < size; ++i)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	int* tempArray = new int[max - min + 1]{};
	for (int i = 0; i < size; ++i)
	{
		tempArray[array[i] - min]++;
	}
	for (int i = 0; i < max - min + 1; ++i)
	{
		while (tempArray[i] > 0)
		{
			tempArray[i]--;
			array[count] = i + min;
			count++;
		}
	}
	delete[] tempArray;
}

int compIncrease(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

void testsCompareArrayAndCopy(int rows, int cols[], int** testArrays, int** testArraysCopy)
{
	for (int i = 0; i < rows; ++i)
	{
		printf("Output for test %i : ", i + 1);
		int count = 0;
		for (int j = 0; j < cols[i]; ++j)
		{
			printf("%i ", testArrays[i][j]);
			if (testArrays[i][j] != testArraysCopy[i][j])
			{
				count++;
			}
			if (j == cols[i] - 1 && count == 0)
			{
				if (count == 0)
				{
					printf("Test %i passed\n", i + 1);
				}
				else
				{
					printf("Test %i failed\n", i + 1);
				}
			}
		}
	}
}

void testsPrintInput(int rows, int cols[], int** testArrays)
{
	for (int i = 0; i < rows; ++i)
	{
		printf("Input for test %i :\n", i + 1);
		for (int j = 0; j < cols[i]; ++j)
		{
			printf("%i ", testArrays[i][j]);
		}
		printf("\n");
	}
}

void testsBubbleAndCountingSorts()
{
	printf("Bubble sort tests\n");
	srand(time(nullptr));
	int const rows = 3;
	int cols[rows] = { 4, 7, 9 };
	// выделение памяти под массив из 3 массивов (проверить сортировку пузырьком)
	int** testArrays = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		testArrays[i] = new int[cols[i]];
	}
	// выделение памяти под копию массива из 3 массивов (отсортируем с помощью встроенной сортировки)
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
	// выводим данные, на которых тестируем
	testsPrintInput(rows, cols, testArrays);
	// сортируем массив с помощью сортировки пузырьком
	int cases = 0;
	// тестировщик выбирает какую из сортировок тестировать (пузырек или подсчетом)
	printf("Enter 1 if you want to test bubble sort\nEnter 2 if you want to test counting sort\n");
	scanf("%i", &cases);
	switch (cases)
	{
	case 1: // пузырек
		printf("Bubble sort test:\n");
		for (int i = 0; i < rows; ++i)
		{
			bubbleSort(cols[i], testArrays[i]);
		}
		break;
	case 2: // сортировка подсчетом
		printf("Counting sort test:\n");
		for (int i = 0; i < rows; ++i)
		{
			countingSort(cols[i], testArrays[i]);
		}
		break;
	default:
		printf("YOU ENTERED DATA THAT IS NOT CORRECT!!!\n");
		break;
	}
	// сортируем копию массива массивов с помощью встроенной сортировки
	for (int i = 0; i < rows; ++i)
	{
		qsort(testArraysCopy[i], cols[i], sizeof(int), compIncrease);
	}
	// сравниваем массив с копией
	testsCompareArrayAndCopy(rows, cols, testArrays, testArraysCopy);
	// освобождение памяти
	for (int i = 0; i < rows; ++i)
	{
		delete[] testArrays[i];
		delete[] testArraysCopy[i];
	}
	delete[] testArrays;
	delete[] testArraysCopy;
}