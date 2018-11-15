#pragma once

struct Node;
struct List;

struct ParseTree
{
	ParseTree();
	~ParseTree();
	void deleteExpression();
	bool isEmpty() const;
	bool printExpression() const;
	void addExpression(char * str);
	int getResult() const;
private:
	int makeOperation(char const operation, int const operand1, int const operand2) const;
	int getResultRecursion(Node const * const current) const;
	void printRecursion(Node const * const current) const;
	void addExpressionRecursion(char * str, Node*& current, int interator);
	void addIfOperator(char* str, Node*& current, int iterator);
	void addIfOperatorAndCurrentIsNullptr(char* str, Node*& current, int iterator);
	void addIfOperatorAndCurrentChildIsNullptr(char* str, Node*& current, Node*& child, int iterator);
	void removeRecursion(Node*& current);
	bool isOperator(char const symbol) const;
	int getPositionOfClosingBracket(char const * str, int iterator) const;
	Node* head;
};