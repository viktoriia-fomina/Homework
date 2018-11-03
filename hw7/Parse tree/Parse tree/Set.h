#pragma once
#include <string>

struct Node;
struct List;

struct Set
{
	Set();
	~Set();
	bool add(char const data);
	bool remove(char const data);
	bool exists(char const data) const;
	bool isEmpty() const;
	bool printInAscendingOrder() const;
	bool printInDescendingOrder() const;
	void addExpression(char const * str);
private:
	int readInfoFromFile();
	void addExpressionRecursion(char * str, int const size, int & interator);
	void addNodeNotToHead(Node* node, char const data);
	void removeRecursion(Node*& current, char const data);
	bool isOperator(char const symbol) const;
	void removeIfChildIsNullptr(Node*& current);
	int maximum(Node const * const current) const;
	void treeTraversal(List & l) const;
	void treeTraversalRecursion(Node const * current, List & l) const;
	Node* head;
};