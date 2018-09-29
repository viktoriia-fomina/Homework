#include "Header.h"

int mostFrequentElement(int size, int* array)
{
	int* arrayCopy = new int[size];
	for (int i = 0; i < size; ++i)
	{
		arrayCopy[i] = array[i];
	}
	quickSort(size, arrayCopy);
	int mostFrequent = 0;
	int count = 0;
	int temporary = array[0];
	int countTemporary = 0;
	for (int i = 0; i < size; ++i)
	{
		if (arrayCopy[i] == temporary && i == size - 1)
		{
			countTemporary++;
			if (countTemporary > count)
			{
				count = countTemporary;
				mostFrequent = temporary;
			}
			break;
		}
		if (arrayCopy[i] == temporary)
		{
			countTemporary++;
		}
		else
		{
			if (countTemporary > count)
			{
				count = countTemporary;
				mostFrequent = temporary;
				temporary = arrayCopy[i];
				countTemporary = 1;
			}
			if (countTemporary < count)
			{
				temporary = arrayCopy[i];
				countTemporary = 1;
			}
		}
	}
	delete[] arrayCopy;
	return mostFrequent;
}

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

void mostFrequentElementTests()
{
	// 3 массива для трех тестов
	int const size1 = 4;
	int array1[size1] = { 1, 3, 3, 4 };
	int const size2 = 7;
	int array2[size2] = { 4, 5, 7, 0,-7 ,8 ,5 };
	int const size3 = 9;
	int array3[size3] = { 6, 6, 9, 0, 3, 9, 4, 9, 9 };

	int result1 = mostFrequentElement(size1, array1);
	if (result1 == 3)
	{
		printf("Test 1 passed\n");
	}
	else
	{
		printf("Test 1 failed with result %i\n", result1);
	}

	int result2 = mostFrequentElement(size2, array2);
	if (result2 == 5)
	{
		printf("Test 2 passed\n");
	}
	else
	{
		printf("Test 2 failed with result %i\n", result2);

	}

	int result3 = mostFrequentElement(size3, array3);
	if (result3 == 9)
	{
		printf("Test 3 passed\n");
	}
	else
	{
		printf("Test 3 failed\n with result %i\n", result3);
	}
}