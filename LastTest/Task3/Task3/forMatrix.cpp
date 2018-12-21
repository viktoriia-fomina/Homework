#include "forMatrix.h"
#include <algorithm>
#include <iostream>

using namespace std;

void toAdgencyMatrix(int numberOfVertexes, int edge, int* arrVertexes, int** adjencyMatrix);

void incidenceMatrixToAdjencyMatrix(int numberOfVertexes, int numberOfEdges,
		int** incidenceMatrix, int** adjencyMatrix)
{
	int* arrVertexes = new int[numberOfVertexes];
	for (int i = 0; i < numberOfEdges; ++i)
	{
		for (int j = 0; j < numberOfVertexes; ++j)
		{
			arrVertexes[j] = incidenceMatrix[j][i];
		}
		toAdgencyMatrix(numberOfVertexes, i, arrVertexes, adjencyMatrix);
	}
	delete[] arrVertexes;
}

void toAdgencyMatrix(int numberOfVertexes, int edge, int* arrVertexes, int** adjencyMatrix)
{
	for (int i = 0; i < numberOfVertexes; ++i)
	{
		for (int j = i; j < numberOfVertexes; ++j)
		{
			if (arrVertexes[i] == 0)
			{
				break;
			}
			else if (arrVertexes[i] == -1 && arrVertexes[j] == 1)
			{
				adjencyMatrix[i][j] = 1;
				adjencyMatrix[j][i] = 0;
			}
		}
	}
}

void reachableVertexes(int numberOfVertexes, int** adjencyMatrix)
{
	int** reachable = new int*[numberOfVertexes];
	for (int i = 0; i < numberOfVertexes; ++i)
	{
		reachable[i] = new int[numberOfVertexes] {};
	}
	for (int i = 0; i < numberOfVertexes; ++i)
	{
		for (int j = 0; j < numberOfVertexes; ++j)
		{
			for (int k = 0; k < numberOfVertexes; ++k)
			{
				reachable[i][j] = std::min(adjencyMatrix[i][j], adjencyMatrix[i][k] + adjencyMatrix[k][j]);
			}
		}
	}
	for (int i = 0; i < numberOfVertexes; ++i)
	{
		for (int j = 0; j < numberOfVertexes; ++j)
		{
			cout << reachable[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < numberOfVertexes; ++i)
	{
		delete[] reachable[i];
	}
	delete[] reachable;
}

//for k = 1 to n
//for i = 1 to n
//for j = 1 to n
//W[i][j] = min(W[i][j], W[i][k] + W[k][j])