#pragma once
#include <iostream>
#include <set>

struct Graph
{
	explicit Graph(int const numberOfVertexes = 0);
	
	~Graph();

	// изменяет размер графа
	void resize(int const numberOfVertexes);

	// возвращает вес ребра
	int edgeWeight(int const vertex1, int const vertex2) const;

	// изменение веса ребра
	int & edgeWeight(int const vertex1, int const vertex2);

	// получить количество вершин
	int getNumberOfVertexes() const;

	// получить множество вершин
	std::set<int> getSetOfVertexes() const;

	// проверка матрицы на симметричность
	void symmetricAdjacencyMatrix() const;

private:
	// инициализация графа (переиспользуется в конструкторе и тд)
	void initialize(int const numberOfVertexes = 0);

	// очищает память (переиспользуется в деструкторе и тд)
	void clear();

	// проверка на то, что значение ребра корректно
	void correctEdge(int const vertex1, int const vertex2) const;

	int numberOfVertexes;
	std::set<int> vertexes;
	int** adjacencyMatrix;
};