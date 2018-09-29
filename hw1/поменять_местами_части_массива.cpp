#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void change(int m, int n, int* array);
void invert(int first, int last, int* array);
void swap(int &a, int &b);

int main()
{
	int m = 0;
	int n = 0;

	printf("Input m : ");
	scanf("%i", &m);
	printf("Input n : ");
	scanf("%i", &n);
	int* array = new int[m + n];
	for (int i = 0; i < m + n; i++)
	{
		array[i] = i + 1;
	}
	for (int i = 0; i < m + n; i++)
	{
		printf("%i\ ", array[i]);
	}
	printf("\n");
	change(m, n, array);
	for (int i = 0; i < m + n; i++)
	{
		printf("%i\ ", array[i]);
	}
	printf("\n");
	delete[] array;
	return 0;
}

void change(int m, int n, int* array)
{
	invert(0, m - 1, array);
	invert(m, m + n - 1, array);
	invert(0, m + n - 1, array);
}

void invert(int first, int last, int* array)
{
	for (int i = 0; i <= (last - first) / 2; ++i)
	{
		swap(array[first + i], array[last - i]);
	}
}

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}