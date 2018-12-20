#pragma once
#include <iostream>
#include <set>

struct Graph
{
	explicit Graph(int const numberOfVertexes);
	
	~Graph();

	int const & edgeWeight(int const vertex1, int const vertex2) const;

	int getNumberOfVertexes() const;

	void printVertexes() const;

	friend std::ostream & operator<<(std::ostream & os, Graph const & graph);

	friend std::istream & operator>>(std::istream & is, Graph & graph);

	std::set<int> subGraphFrontier(std::set<int> const & subGraph) const;

	std::set<int> subGraph

private:
	int & edgeWeight(int const vertex1, int const vertex2);
	int numberOfVertexes;
	std::set<int> vertexes;
	int** adjacencyMatrix;
};