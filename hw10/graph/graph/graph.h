#pragma once
#include <iostream>

struct Graph
{
	explicit Graph(int const numberOfVertexes);
	
	~Graph();

	int const & operator()(int const i, int const j) const;

	friend std::ostream & operator<<(std::ostream & os, Graph const & graph);

	friend std::istream & operator>>(std::istream & is, Graph & graph);
private:
	int & operator()(int const i, int const j);
	int numberOfVertexes;
	int** adjacencyMatrix;
};