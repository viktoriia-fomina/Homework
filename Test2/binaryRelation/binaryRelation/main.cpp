//По бинарному отношению на множестве из n элементов построить его транзитивное замыкание.
//В файле указано число n и матрица n*n, задающая отношение(в ячейке(i, j) стоит 1, если пара элементов(i, j) 
//	принадлежит отношению и 0 в противном случае).Вывести в другой файл матрицу, задающую транзитивное 
//	замыкание этого отношения.

#include <iostream>
#include "workWithFiles.h"

using namespace std;

int main()
{
	ifstream fileToRead;
	fileToRead.open("input.txt", ios::in);
	int size = readNumberFromFile(fileToRead);
	int** matrix = createMatrix(size);
	readMatrixFromFile(fileToRead, matrix, size);
	ofstream fileToWrite;
	fileToWrite.open("output.txt");
	int** matrixToWrite = createMatrix(size);
	transitiveClosure(matrix, matrixToWrite, size, fileToWrite);
	fileToRead.close();
	fileToWrite.close();
	for (int i = 0; i < size; ++i)
	{
		delete[] matrix[i];
		delete[] matrixToWrite[i];
	}
	delete matrix;
	delete matrixToWrite;

	return 0;
}