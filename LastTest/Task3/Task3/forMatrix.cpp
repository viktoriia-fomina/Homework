#include "forMatrix.h"
#include <algorithm>
#include <iostream>

using namespace std;

void toAdgencyMatrix(int numberOfVertexes, int* arrVertexes, int** adjencyMatrix);

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
		toAdgencyMatrix(numberOfVertexes, arrVertexes, adjencyMatrix);
	}
	delete[] arrVertexes;
}

void toAdgencyMatrix(int numberOfVertexes, int* arrVertexes, int** adjencyMatrix)
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
				adjencyMatrix[i][j] = 0;
				adjencyMatrix[j][i] = 1;
			}
			else if (arrVertexes[i] == 1 && arrVertexes[j] == -1)
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

	bool reachableVer = true;
	for (int i = 0; i < numberOfVertexes; ++i)
	{
		reachableVer = true;
		for (int j = 0; j < numberOfVertexes; ++j)
		{
			if (reachable[i][j] == 0)
			{
				if (i != j)
				{
					reachableVer = false;
					break;
				}
			}
		}
		if (reachableVer)
		{
			cout << i << endl;
		}
	}

	for (int i = 0; i < numberOfVertexes; ++i)
	{
		delete[] reachable[i];
	}
	delete[] reachable;
}