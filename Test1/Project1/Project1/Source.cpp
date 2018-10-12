// Реализовать сортировку выбором.Сортируемый массив(размером в 10 элементов) 
// вводится с клавиатуры.Сортировка выбором - это та, где в неотсортированной части массива 
// ищется минимальный элемент и добавляется к отсортированной части.

#include "Header.h"

void swap(int & a, int & b);

void selectionSort(int size, int* array)
{
	for (int i = 0; i < size; ++i)
	{
		int min = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		swap(array[i], array[min]);
	}
}

void swap(int & a, int & b)
{
	int const c = a;
	a = b;
	b = c;
}