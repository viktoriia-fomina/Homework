#include "workWithFiles.h"
#include <iostream>

using namespace std;

int readNumberFromFile(ifstream & file)
{
	if (!file.is_open())
	{
		cout << "File not found" << endl;
		return -1;
	}
	int number = 0;
	if (!file.eof())
	{
		file >> number;
	}
	return number;
}

int** createMatrix(int number)
{
	int** matrix = new int*[number];
	for (int i = 0; i < 5; ++i)
	{
		matrix[i] = new int[5];
	}
	return matrix;
}

bool readMatrixFromFile(ifstream & file, int** matrix, int N)
{
	if (!file.is_open())
	{
		cout << "File not found" << endl;
		return false;
	}
	int buffer = 0;
	while (!file.eof())
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				file >> buffer;
				matrix[i][j] = buffer;
			}
		}
	}
	return true;
}

bool transitiveClosure(int** matrix, int** matrixToWrite, int N, ofstream & fileToWrite)
{
	if (!fileToWrite.is_open())
	{
		cout << "File not found" << endl;
		return false;
	}
	fileToWrite << N << endl;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				matrixToWrite[j][k] = matrix[j][k] || (matrix[j][i] && matrix[i][k]);
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			fileToWrite << matrixToWrite[i][j] << " ";
		}
		fileToWrite << endl;
	}
	return true;
}