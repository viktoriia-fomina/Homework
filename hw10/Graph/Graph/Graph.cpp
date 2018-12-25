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

}

istream & operator>>(std::istream & is, Graph & graph)
{

}

void Graph::symmetricAndNoLoopsAdjacencyMatrix() const
{

}

void Graph::init(int const numberOfVertexes)
{

}

void Graph::clear()
{

}

void Graph::correctEdge(int const vertex1, int const vertex2) const
{

}