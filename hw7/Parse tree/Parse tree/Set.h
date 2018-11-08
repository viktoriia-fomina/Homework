#pragma once
#include <string>

struct Node;
struct List;

struct Set
{
	Set();
	~Set();
	bool add(char const data);
	bool exists(char const data) const;
	bool isEmpty() const;
	bool printExpression() const;
	void addExpression(char * str);
	int getResult() const;
private:
	int readInfoFromFile();
	int makeOperation(char const operation, int const operand1, int const operand2) const;
	int getResultRecursion(Node const * const current) const;
	void printRecursion(Node const * const current) const;
	void addExpressionRecursion(char * str, Node*& current, int interator);
	void addIfOperator(char* str, Node*& current, int iterator);
	void addIfOperatorAndCurrentIsNullptr(char* str, Node*& current, int iterator);
	void addIfOperatorAndCurrentLeftChildIsNullptr(char* str, Node*& current, int iterator);
	void addIfOperatorAndCurrentRightChildIsNullptr(char* str, Node*& current, int iterator);
	void addNodeNotToHead(Node* node, char const data);
	void removeRecursion(Node*& current);
	bool isOperator(char const symbol) const;
	bool isNumber(char const symbol) const;
	int getPositionOfClosingBracket(char const * str, int iterator) const;
	void treeTraversal(List & l) const;
	void treeTraversalRecursion(Node const * current, List & l) const;
	void existsRecursion(char const data, Node const * const current, bool & exists) const;
	Node* head;
};