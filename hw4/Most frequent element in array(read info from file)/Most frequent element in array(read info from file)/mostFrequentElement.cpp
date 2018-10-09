#include "mostFrequentElement.h"
#include "quickSort.h"

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
		if (arrayCopy[i] == temporary)
		{
			countTemporary++;
		}
		else
		{
			if (countTemporary >= count)
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
	if (arrayCopy[size - 1] == temporary)
	{
		countTemporary++;
		if (countTemporary > count)
		{
			count = countTemporary;
			mostFrequent = temporary;
		}
	}
	delete[] arrayCopy;
	return mostFrequent;
}