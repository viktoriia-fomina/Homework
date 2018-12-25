#pragma once
#include <iostream>
#include <set>

struct Graph
{
	explicit Graph(int const numberOfVertexes = 0);

	~Graph();

	void resize(int const numberOfVertexes);

	int const & edgeWeight(int const vertex1, int const vertex2) const;

	int & edgeWeight(int const vertex1, int const vertex2);

	int getNumberOfVertexes() const;

	std::set<int> getSetOfVertexes() const;

	friend std::ostream & operator<<(std::ostream & os, Graph const & graph);

	friend std::istream & operator>>(std::istream & is, Graph & graph);

	void symmetricAndNoLoopsAdjacencyMatrix() const;

private:
	void init(int const numberOfVertexes = 0);
	void clear();
	void correctEdge(int const vertex1, int const vertex2) const;

	int numberOfVertexes;
	std::set<int> vertexes;
	int** adjacencyMatrix;
};
