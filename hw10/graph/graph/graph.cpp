#include "graph.h"
#include <set>
#include <cassert>

using namespace std;

void Graph::initialize(int const numberOfVertexes)
{
	assert(numberOfVertexes >= 0);
	if (numberOfVertexes == 0)
	{
		this->numberOfVertexes = 0;
		this->adjacencyMatrix = nullptr;
	}
	else
	{
		this->numberOfVertexes = numberOfVertexes;
		adjacencyMatrix = new int*[numberOfVertexes];
		for (int i = 0; i < numberOfVertexes; ++i)
		{
			adjacencyMatrix[i] = new int[numberOfVertexes] {};
			vertexes.insert(i);
		}
	}
}

void Graph::clear()
{
	if (numberOfVertexes != 0)
	{
		for (int i = 0; i < numberOfVertexes; ++i)
		{
			delete[] adjacencyMatrix[i];
		}
		delete[] adjacencyMatrix;
		numberOfVertexes = 0;
	}
}

void Graph::correctEdge(int const vertex1, int const vertex2) const
{
	assert(numberOfVertexes > 0);
	assert(vertex1 >= 0 && vertex2 >= 0);
	assert(vertex1 < numberOfVertexes && vertex2 < numberOfVertexes);
}

void Graph::symmetricAdjacencyMatrix() const
{
	bool symmetric = true;
	for (int diag = 1; diag < numberOfVertexes; ++diag)
	{
		for (int posOnDiag = 0; posOnDiag < numberOfVertexes - diag; posOnDiag++)
		{
			int const row = posOnDiag;
			int const column = diag + posOnDiag;
			if (edgeWeight(row, column) != edgeWeight(column, row))
			{
				symmetric = false;
				assert(symmetric);
			}
		}
	}
	for (int i = 0; i < numberOfVertexes; ++i)
	{
		if (edgeWeight(i, i) != 0)
		{
			symmetric = false;
			assert(symmetric);
		}
	}
}

Graph::Graph(int const numberOfVertexes)
{
	initialize(numberOfVertexes);
}

void Graph::resize(int const numberOfVertexes)
{
	clear();
	initialize(numberOfVertexes);
}

Graph::~Graph()
{
	clear();
}

int & Graph::edgeWeight(int const vertex1, int const vertex2)
{
	correctEdge(vertex1, vertex2);
	return adjacencyMatrix[vertex1][vertex2];
}

int Graph::edgeWeight(int const vertex1, int const vertex2) const
{
	correctEdge(vertex1, vertex2);
	return adjacencyMatrix[vertex1][vertex2];
}

int Graph::getNumberOfVertexes() const
{
	return numberOfVertexes;
}

set<int> Graph::getSetOfVertexes() const
{
	return vertexes;
}