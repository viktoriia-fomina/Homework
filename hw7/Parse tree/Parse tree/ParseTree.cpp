#include "ParseTree.h"
#include "Node.h"
#include "List.h"
#include <iostream>
#include <cctype>

using namespace std;

ParseTree::ParseTree()
{
	head = nullptr;
}

ParseTree::~ParseTree()
{
	deleteExpression();
}

void ParseTree::deleteExpression()
{
	if (!isEmpty())
	{
		removeRecursion(head);
		head = nullptr;
	}
}

void ParseTree::removeRecursion(Node*& current)
{
	if (current->leftChild != nullptr)
	{
		removeRecursion(current->leftChild);
	}
	if (current->rightChild != nullptr)
	{
		removeRecursion(current->rightChild);
	}
	delete current;
}

bool ParseTree::isEmpty() const
{
	return head == nullptr;
}

bool ParseTree::printExpression() const
{
	if (isEmpty())
	{
		return false;
	}
	printRecursion(head);
	return true;
}

void ParseTree::printRecursion(Node const * const current) const
{
	if (isOperator(current->data))
	{
		cout << "(" << current->data;
		printRecursion(current->leftChild);
		printRecursion(current->rightChild);
	}
	else
	{
		cout << current->data;
		if (current->parent->rightChild == current)
		{
			auto* last = current;
			auto* temp = current->parent;
			while (temp != nullptr && temp->rightChild == last)
			{
				cout << ")";
				temp = temp->parent;
				last = last->parent;
			}
		}
	}
}

int ParseTree::getResult() const
{
	if (isEmpty())
	{
		return -1;
	}
	return getResultRecursion(head);
}

int ParseTree::getResultRecursion(Node const * const current) const
{
	int leftChild = 0;
	int rightChild = 0;
	if (isdigit(current->leftChild->data))
	{
		leftChild = current->leftChild->data - '0';
	}
	else
	{
		leftChild = getResultRecursion(current->leftChild);
	}
	if (isdigit(current->rightChild->data))
	{
		rightChild = current->rightChild->data - '0';
	}
	else
	{
		rightChild = getResultRecursion(current->rightChild);
	}
	int result = makeOperation(current->data, leftChild, rightChild);
	return result;
}

int ParseTree::makeOperation(char const operation, int const operand1, int const operand2) const
{
	switch (operation)
	{
	case '+':
		return operand1 + operand2;
	case '-':
		return operand1 - operand2;
	case '*':
		return operand1 * operand2;
	case '/':
		return operand1 / operand2;
	default:
		cout << "Expression can not be calculated as operator was not found" << endl;
	}
}

void ParseTree::addExpression(char * str)
{
	int i = 0;
	addExpressionRecursion(str, head, i);	
}

void ParseTree::addExpressionRecursion(char * str, Node*& current, int iterator)
{
	if (str[iterator] == '\0')
	{
		return;
	}
	if (isOperator(str[iterator]))
	{
		addIfOperator(str, current, iterator);
	}
	else if (str[iterator] == '(')
	{
		addExpressionRecursion(str, current, iterator + 1);
	}
	else if (isdigit(str[iterator]))
	{
		if (current->leftChild == nullptr)
		{
			current->leftChild = new Node(str[iterator]);
			current->leftChild->parent = current;
		}
		else
		{
			current->rightChild = new Node(str[iterator]);
			current->rightChild->parent = current;
		}
	}
}

void ParseTree::addIfOperator(char* str, Node*& current, int iterator)
{
	if (current == nullptr)
	{
		addIfOperatorAndCurrentIsNullptr(str, current, iterator);
	}
	else if (current->leftChild == nullptr)
	{
		//addIfOperatorAndCurrentLeftChildIsNullptr(str, current, iterator);
		addIfOperatorAndCurrentChildIsNullptr(str, current, current->leftChild, iterator);
	}
	else
	{
		//addIfOperatorAndCurrentRightChildIsNullptr(str, current, iterator);
		addIfOperatorAndCurrentChildIsNullptr(str, current, current->rightChild, iterator);
	}
}

void ParseTree::addIfOperatorAndCurrentIsNullptr(char* str, Node*& current, int iterator)
{
	int position = 0;
	current = new Node(str[iterator]);
	if (str[iterator + 1] == '(')
	{
		position = getPositionOfClosingBracket(str, iterator + 2);
		addExpressionRecursion(str, current, iterator + 2);
		addExpressionRecursion(str, current, position + 1);
	}
	else
	{
		addExpressionRecursion(str, current, iterator + 1);
		addExpressionRecursion(str, current, iterator + 2);
	}
}

//void ParseTree::addIfOperatorAndCurrentLeftChildIsNullptr(char* str, Node*& current, int iterator)
//{
//	int position = 0;
//	current->leftChild = new Node(str[iterator]);
//	current->leftChild->parent = current;
//	if (str[iterator + 1] == '(')
//	{
//		position = getPositionOfClosingBracket(str, iterator + 2);
//		addExpressionRecursion(str, current->leftChild, iterator + 2);
//		addExpressionRecursion(str, current->leftChild, position + 1);
//	}
//	else
//	{
//		addExpressionRecursion(str, current->leftChild, iterator + 1);
//		addExpressionRecursion(str, current->leftChild, iterator + 2);
//	}
//}

//void ParseTree::addIfOperatorAndCurrentRightChildIsNullptr(char* str, Node*& current, int iterator)
//{
//	int position = 0;
//	current->rightChild = new Node(str[iterator]);
//	current->rightChild->parent = current;
//	if (str[iterator + 1] == '(')
//	{
//		position = getPositionOfClosingBracket(str, iterator + 2);
//		addExpressionRecursion(str, current->rightChild, iterator + 2);
//		addExpressionRecursion(str, current->rightChild, position + 1);
//	}
//	else
//	{
//		addExpressionRecursion(str, current->rightChild, iterator + 1);
//		addExpressionRecursion(str, current->rightChild, iterator + 2);
//	}
//}

void ParseTree::addIfOperatorAndCurrentChildIsNullptr(char* str, Node*& current, Node*& child, int iterator)
{
	int position = 0;
	child = new Node(str[iterator]);
	child->parent = current;
	if (str[iterator + 1] == '(')
	{
		position = getPositionOfClosingBracket(str, iterator + 2);
		addExpressionRecursion(str, child, iterator + 2);
		addExpressionRecursion(str, child, position + 1);
	}
	else
	{
		addExpressionRecursion(str, child, iterator + 1);
		addExpressionRecursion(str, child, iterator + 2);
	}
}

int ParseTree::getPositionOfClosingBracket(char const * str, int iterator) const
{
	int openingBrackets = 1;
	++iterator;
	while (openingBrackets != 0 && str[iterator] != '\0')
	{
		if (str[iterator] == '(')
		{
			++openingBrackets;
		}
		else if (str[iterator] == ')')
		{
			--openingBrackets;
		}
		++iterator;
	}
	return iterator - 1;
}

bool ParseTree::isOperator(char const symbol) const
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}