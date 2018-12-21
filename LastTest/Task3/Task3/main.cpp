#include <iostream>
#include "forMatrix.h"

//Тест, 3.3
//Дан ориентированный граф в виде матрицы инцидентности.Написать функцию поиска таких вершин, 
//которые достижимы из всех остальных вершин(то есть из любой вершины графа можно построить путь в 
//эту вершину).

using namespace std;

int main()
{
	int numberOfVertexes;
	cout << "Input number of vertexes" << endl;
	cin >> numberOfVertexes;
	int numberOfEdges;
	cout << "Input number of edges" << endl;
	cin >> numberOfEdges;
	int** incidenceMatrix = new int*[numberOfVertexes];

	for (int i = 0; i < numberOfVertexes; ++i)
	{
		incidenceMatrix[i] = new int[numberOfEdges] {};
	}

	cout << "Fill incidence matrix in the values" << endl;

	for (int i = 0; i < numberOfVertexes; ++i)
	{
		for (int j = 0; j < numberOfEdges; ++j)
		{
			cin >> incidenceMatrix[i][j];
		}
	}
	cout << endl;

	int** adjencyMatrix = new int*[numberOfVertexes];
	for (int i = 0; i < numberOfVertexes; ++i)
	{
		adjencyMatrix[i] = new int[numberOfVertexes] {};
	}

	incidenceMatrixToAdjencyMatrix(numberOfVertexes, numberOfEdges, incidenceMatrix, adjencyMatrix);

	for (int i = 0; i < numberOfVertexes; ++i)
	{
		for (int j = 0; j < numberOfVertexes; ++j)
		{
			cout << adjencyMatrix[i][j] << " ";
		}
		cout << endl;
	}

	reachableVertexes(numberOfVertexes, adjencyMatrix);

	for (int i = 0; i < numberOfVertexes; ++i)
	{
		delete[] adjencyMatrix[i];
	}
	delete[] adjencyMatrix;

	for (int i = 0; i < numberOfVertexes; ++i)
	{
		delete[] incidenceMatrix[i];
	}
	delete[] incidenceMatrix;

	return 0;
}