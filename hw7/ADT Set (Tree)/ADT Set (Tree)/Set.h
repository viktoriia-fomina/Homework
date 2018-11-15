#pragma once

struct Node;
struct List;

struct Set
{
	Set();
	~Set();
	bool add(int const data);
	bool remove(int const data);
	bool exists(int const data) const;
	bool isEmpty() const;
	bool printInAscendingOrder() const;
	bool printInDescendingOrder() const;
private:
	void removeSetRecursion(Node* node);
	void addNodeNotToHead(Node* node, int const data);
	void removeRecursion(Node*& current, int const data);
	void removeIfChildIsNullptr(Node*& current);
	int maximum(Node const * const current) const;
	void treeTraversal(List & l) const;
	void treeTraversalRecursion(Node const * current, List & l) const;
	Node* head;
};