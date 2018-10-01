#include "Header.h"

void quickSortTests();
void testCompareArrayAndCopy(int const numberOfTest, int const size, int const &array, 
		int const &copyArray1);
int compIncrease(const void* a, const void* b);

int main()
{
	quickSortTests();

	return 0;
}

void quickSortTests()
{
	printf("Quick sort tests\n");
	srand(time(nullptr));
	int const size1 = 4;
	int const size2 = 7;
	int const size3 = 15;
	// создадим три массива (проверить сортировку)
	int array1[size1]{ 1, 9, -5, 7 };
	int array2[size2]{ 5, 5, 5, 5, 5, 5, 5 };
	int array3[size3]{ -9, 0, -4, 8, 90, -101, 101, 0, 7, 7, 9, 4, 6, 1, -14 };
	// создаем три массива-копии (отсортируем с помощью встроенной сортировки)
	int copyArray1[size1]{};
	int copyArray2[size2]{};
	int copyArray3[size3]{};
	// заполнение массивов-копий
	for (int i = 0; i < size1; ++i)
	{
		copyArray1[i] = array1[i];
	}
	for (int i = 0; i < size2; ++i)
	{
		copyArray2[i] = array2[i];
	}
	for (int i = 0; i < size3; ++i)
	{
		copyArray3[i] = array3[i];
	}
	// сортируем массивы с помощью тестируемой сортировки
	quickSort(size1, array1);
	quickSort(size2, array2);
	quickSort(size3, array3);
	// сортируем массивы-копии с помощью встроенной сортировки
	qsort(copyArray1, size1, sizeof(int), compIncrease);
	qsort(copyArray2, size2, sizeof(int), compIncrease);
	qsort(copyArray3, size3, sizeof(int), compIncrease);
	// сравниваем массив с копией
	testCompareArrayAndCopy(1, size1, *array1, *copyArray1);
	testCompareArrayAndCopy(2, size2, *array2, *copyArray2);
	testCompareArrayAndCopy(3, size3, *array3, *copyArray3);
}

void testCompareArrayAndCopy(int const numberOfTest, int const size, int const &array, 
		int const &copyArray)
{
	bool ifArraysAreTheSame = true;
	for (int i = 0; i < size; ++i)
	{
		if ((&array)[i] != (&copyArray)[i])
		{
			ifArraysAreTheSame = false;
			break;
		}
	}
	if (ifArraysAreTheSame)
	{
		printf("Test %i passed\n", numberOfTest);
	}
	else
	{
		printf("Test %i failed\n", numberOfTest);
	}
}

int compIncrease(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}