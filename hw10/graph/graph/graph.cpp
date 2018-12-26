#include "graph.h"

Graph::Graph(int const vertexesNumber, int** adjacencyMatrix)
{
	
}

Graph::Graph(int const vertexesNumber, int const edgesNumber, int** incidenceMatrix)
{

}

Graph::~Graph()
{
	for (int vertNumber = 0; vertNumber < vertexesNumber; ++vertNumber)
	{
		delete adjacencyMatrix[vertNumber];
	}
	delete[] adjacencyMatrix;

	for (int vertNumber = 0; vertNumber < vertexesNumber; ++vertNumber)
	{
		delete incidenceMatrix[vertNumber];
	}
	delete[] incidenceMatrix;
}

int** Graph::adjancencyMatrixToIncidence(int const vertexesNumber, int & edgesNumber, 
		int** adjancencyMatrix) const
{
	
}

int** Graph::incidenceMatrixToAdjancency(int const vertexesNumber, int const edgesNumber,
		int** adjancencyMatrix) const
{

}

bool Graph::matrixIsSymmetric(int const rawsOrColumnsNumber, int const * const * const matrix) const
{
	for (int currentRaw = 0; currentRaw < rawsOrColumnsNumber; ++currentRaw)
	{
		for (int currentColumn = rawsOrColumnsNumber; currentColumn < rawsOrColumnsNumber; ++currentColumn)
		{
			if (matrix[currentRaw][currentColumn] != matrix[currentColumn][currentRaw])
			{
				return false;
			}
		}
	}
	return true;
}