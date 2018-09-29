#include "Header.h"

void quickSort(int const size, int* array)
{
	int first = 0;
	int last = size - 1;
	int pivotAdress = arrayPartition(size, array);
	if (last - first > 8)
	{
		quickSort(pivotAdress, array);
		quickSort(size - pivotAdress - 1, array + pivotAdress + 1);
	}
	else
	{
		insertionSort(size, array);
	}
}

int arrayPartition(int const size, int* array)
{
	int first = 0;
	int last = size - 1;
	int pivotAdress = pivotIndex(first, last, array);
	int pivot = array[pivotAdress];
	swap(array[pivotAdress], array[first]);
	pivotAdress = first;
	for (int i = first + 1; i < last + 1; ++i)
	{
		if (array[i] < pivot)
		{
			if (pivotAdress - i == 1)
			{
				swap(array[i], array[pivotAdress]);
				pivotAdress++;
			}
			else
			{
				swap(array[i], array[pivotAdress + 1]);
				swap(array[pivotAdress], array[pivotAdress + 1]);
				pivotAdress++;
			}
		}
	}
	return pivotAdress;
}

int pivotIndex(int const first, int const last, int const * const array)
{
	if (first - last >= 2)
	{
		return middleOfThreeIndex(first, last, array);
	}
	else
	{
		return 0;
	}
}

int middleOfThreeIndex(int const first, int const last, int const * const array)
{
	int middle = first;
	if (array[middle] > array[(last + first) / 2] && middle > array[last])
	{
		int indexOfMax = indexOfMaxOfTwo((last + first) / 2, last, array);
		middle = indexOfMax;
	}
	if (array[middle] < array[(last + first) / 2] && middle < array[last])
	{
		int indexOfMin = indexOfMinOfTwo((last + first) / 2, last, array);
		middle = indexOfMin;
	}
	return middle;
}

int indexOfMaxOfTwo(int const index1, int const index2, int const * const array)
{
	int max = index1;
	if (array[max] < array[index2])
	{
		max = index2;
	}
	return max;
}

int indexOfMinOfTwo(int const index1, int const index2, int const * const array)
{
	int min = index1;
	if (array[min] > array[index2])
	{
		min = index2;
	}
	return min;
}

void insertionSort(int const size, int* array)
{
	for (int i = 1; i < size; ++i)
	{
		siftLeft(i, array);
	}
}

void siftLeft(int const position, int* array)
{
	int i = position - 1;
	while (array[i] > array[i + 1] && i >= 0)
	{
		swap(array[i], array[i + 1]);
		--i;
	}
}

void swap(int & a, int & b)
{
	int c = a;
	a = b;
	b = c;
}

void quickSortTests()
{
	printf("Quick sort tests\n");
	srand(time(nullptr));
	int const rows = 3;
	int cols[rows] = { 4, 7, 15 };
	// выделение памяти под массив из 3 массивов (проверить сортировку)
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
	// сортируем массив с помощью тестируемой сортировки
	for (int i = 0; i < rows; ++i)
	{
		quickSort(cols[i], testArrays[i]);
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

void testsPrintInput(int const rows, int const cols[], int const * const * const testArrays)
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

void testsCompareArrayAndCopy(int const rows, int const cols[], int const * const * const testArrays, 
		int const * const * const testArraysCopy)
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
					printf("\nTest %i passed\n", i + 1);
				}
				else
				{
					printf("\nTest %i failed\n", i + 1);
				}
			}
		}
	}
}

int compIncrease(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}