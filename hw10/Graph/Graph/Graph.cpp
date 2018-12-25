#include "graph.h"
#include <iostream>
#include <set>
#include <vector>
#include <cassert>
#include <limits>

using namespace std;

Graph::Graph(int const numberOfVertexes)
{
	init(numberOfVertexes);
}

Graph::~Graph()
{
	clear();
}

void Graph::resize(int const numberOfVertexes)
{
	clear();
	init(numberOfVertexes);
}

int const & Graph::edgeWeight(int const vertex1, int const vertex2) const
{
	correctEdge(vertex1, vertex2);
	return adjacencyMatrix[vertex1][vertex2];
}

int & Graph::edgeWeight(int const vertex1, int const vertex2)
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

ostream & operator<<(std::ostream & os, Graph const & graph)
{
	if (graph.getNumberOfVertexes() == 0)
	{
		os << "Graph is empty." << endl;
		return os;
	}
	for (int vertex1 = 0; vertex1 < graph.getNumberOfVertexes(); ++vertex1)
	{
		for (int vertex2 = 0; vertex2 < graph.getNumberOfVertexes(); ++vertex2)
		{
			os << graph.edgeWeight(vertex1, vertex2) << " ";
		}
		os << endl;
	}
	return os;
}

istream & operator>>(std::istream & is, Graph & graph)
{
	assert(graph.numberOfVertexes > 0);
	for (int vertex1 = 0; vertex1 < graph.getNumberOfVertexes(); ++vertex1)
	{
		for (int vertex2 = 0; vertex2 < graph.getNumberOfVertexes(); ++vertex2)
		{
			is >> graph.edgeWeight(vertex1, vertex2);
		}
	}
	graph.symmetricAndNoLoopsAdjacencyMatrix();
	return is;
}

void Graph::symmetricAndNoLoopsAdjacencyMatrix() const
{

}

void Graph::init(int const numberOfVertexes)
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