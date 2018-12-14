#include "saddlePoints.h"
#include <iostream>

using namespace std;

int getMinInRow(int* row, int cols);

int getMaxInCol(int** array, int rows, int coleNumber);

void saddlePoints(int** array, int rows, int cols)
{
	int* minInRows = new int[rows] {};
	int* maxInCols = new int[cols] {};

	for (int i = 0; i < cols; ++i)
	{
		minInRows[i] = getMinInRow(array[i], cols);
	}
	for (int i = 0; i < rows; ++i)
	{
		maxInCols[i] = getMaxInCol(array, rows, i);
	}
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (array[i][j] == minInRows[i] && array[i][j] == maxInCols[j])
			{
				cout << "(" << i << "; " << j << ")" << endl;
			}
		}
	}

	delete[] minInRows;
	delete[] maxInCols;
}

int getMinInRow(int* row, int cols)
{
	int min = row[0];
	for (int i = 0; i < cols; ++i)
	{
		if (row[i] < min)
		{
			min = row[i];
		}
	}
	return min;
}

int getMaxInCol(int** array, int rows, int coleNubmer)
{
	int max = array[0][coleNubmer];
	for (int i = 0; i < rows; ++i)
	{
		if (array[i][coleNubmer] > max)
		{
			max = array[i][coleNubmer];
		}
	}
	return max;
}