#include "Header.h"

bool binarySearch(int const number, int size, int const * const array)
{
	int left = 0;
	int right = size - 1;
	int middle = (left + right) / 2;
	if (left == right)
	{
		if (array[left] == number)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (array[middle] == number)
	{
		return true;
	}
	else if (array[middle] > number)
	{
		if (array[left] > number)
		{
			return false;
		}
		else
		{
			return ifElementIsInArray(number, middle, array);
		}
	}
	else
	{
		if (array[left] > number || array[right] < number)
		{
			return false;
		}
		else
		{
			return ifElementIsInArray(number, right - middle, array + middle + 1);
		}
	}
}

bool ifElementIsInArray(int const number, int const size, int const * const array)
{
	int* arrayCopy = new int[size];
	for (int i = 0; i < size; ++i)
	{
		arrayCopy[i] = array[i];
	}
	quickSort(size, arrayCopy);
	bool flagIfElementIsInArray = binarySearch(number, size, arrayCopy);
	delete[] arrayCopy;
	return flagIfElementIsInArray;
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