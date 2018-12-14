//Написать программу поиска седловых точек двумерного массива.Седловая точка — это элемент, 
//наименьший в своей строке и наибольший в своем столбце.

#include <iostream>
#include "saddlePoints.h"

using namespace std;

int main()
{
	int rows = 0;
	int cols = 0;
	cout << "Input number of rows" << endl;
	cin >> rows;
	cout << "Input number of cols" << endl;
	cin >> cols;
	cout << "Input elements of array" << endl;
	int** array = new int * [rows];
	for (int i = 0; i < rows; ++i)
	{
		array[i] = new int[cols];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cin >> array[i][j];
		}
	}

	cout << "Saddle points:" << endl;
	saddlePoints(array, rows, cols);

	for (int i = 0; i < rows; ++i)
	{
		delete[] array[i];
	}
	delete[] array;

	return 0;
}