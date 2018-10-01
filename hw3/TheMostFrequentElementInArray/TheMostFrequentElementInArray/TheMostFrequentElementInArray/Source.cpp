#include "Header.h"

void quickSort(int const size, int* array);
int arrayPartition(int const size, int* array);
int pivotIndex(int const first, int const last, int const * const array);
int middleOfThreeIndex(int const first, int const last, int const * const array);
int indexOfMaxOfTwo(int const index1, int const index2, int const * const array);
int indexOfMinOfTwo(int const index1, int const index2, int const * const array);
void insertionSort(int const size, int* array);
void siftLeft(int const position, int* array);
void swap(int & a, int & b);

int mostFrequentElement(int const size, int* array)
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
	int const first = 0;
	int const last = size - 1;
	if (last - first > 8)
	{
		int const pivotAdress = arrayPartition(size, array);
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
	int const first = 0;
	int const last = size - 1;
	int pivotAdress = pivotIndex(first, last, array);
	int const pivot = array[pivotAdress];
	swap(array[pivotAdress], array[first]);
	pivotAdress = first;
	for (int i = first + 1; i < last + 1; ++i)
	{
		if (array[i] < pivot)
		{
			if (pivotAdress - i == 1)
			{
				swap(array[i], array[pivotAdress]);
			}
			else
			{
				swap(array[i], array[pivotAdress + 1]);
				swap(array[pivotAdress], array[pivotAdress + 1]);
			}
			pivotAdress++;
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
	int const c = a;
	a = b;
	b = c;
}