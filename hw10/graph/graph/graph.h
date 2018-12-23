#pragma once

class Graph
{
public:
	Graph(int const vertexesNumber, int** adjacencyMatrix);
	Graph(int const vertexesNumber, int const edgesNumber, int** incidenceMatrix);
	~Graph();
	

private:
	int** adjancencyMatrixToIncidence(int const vertexes, int & edgesNumber, int** adjancencyMatrix) const;
	int** incidenceMatrixToAdjancency(int const vertexes, int const edgesNumber, int** adjancencyMatrix) const;
	bool matrixIsSymmetric(int const rawsOrColumnsNumber, int const * const * const matrix) const;

	int vertexesNumber;
	int edgesNumber;
	int** adjacencyMatrix;
	int**incidenceMatrix;
};