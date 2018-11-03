#pragma once

struct Node;
struct List;

struct Set
{
	Set();
	~Set();
	bool add(int const data);
	bool remove(int const data);
	bool exists(int const data);
	bool isEmpty();
	bool printInAscendingOrder();
	bool printInDescendingOrder();
private:
	void addNodeNotToHead(Node* node, int const data);
	void removeRecursion(Node*& current, int const data);
	void removeIfChildIsNullptr(Node*& current);
	int maximum(Node const * const current);
	void treeTraveral(List & l);
	void treeTraveralRecursion(Node const * current, List & l);
	Node* head;
};