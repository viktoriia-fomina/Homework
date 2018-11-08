#include "Set.h"
#include "Node.h"
#include "List.h"
Set::Set()
{
	head = nullptr;
}

Set::~Set()
{
	if (!isEmpty())
	{
		removeRecursion(head);
	}
}

void Set::removeRecursion(Node*& current)
{
	if (current->leftChild != nullptr)
	{
		auto* tempLeftChild = current->leftChild;
		removeRecursion(tempLeftChild);
	}
	if (current->rightChild != nullptr)
	{
		auto* tempRightChild = current->rightChild;
		removeRecursion(tempRightChild);
	}
	delete current;
}

bool Set::isEmpty() const
{
	return head == nullptr;
}

bool Set::printExpression() const
{
	if (isEmpty())
	{
		return false;
	}
	printRecursion(head);
	return true;
}

void Set::printRecursion(Node const * const current) const
{
	if (current == head)
	{
		cout << head->data;
		printRecursion(current->leftChild);
		printRecursion(current->rightChild);
	}
	else if (isOperator(current->data))
	{
		cout << "(" << current->data;
		printRecursion(current->leftChild);
		printRecursion(current->rightChild);
	}
	else
	{
		cout << current->data;
		if (current->parent->rightChild == current && isNumber(current->parent->leftChild->data))
		{
			cout << ")";
		}
	}
}

int Set::getResultOfExpression() const
{
	if (isEmpty())
	{
		return -1;
	}
	return getResultRecursion(head);
}

int Set::getResultRecursion(Node const * const current) const
{
	int leftChild = 0;
	int rightChild = 0;
	if (isNumber(current->leftChild->data))
	{
		leftChild = atoi(&(current->leftChild->data));
	}
	else
	{
		leftChild = getResultRecursion(current->leftChild);
	}
	if (isNumber(current->rightChild->data))
	{
		rightChild = atoi(&(current->rightChild->data));
	}
	else
	{
		rightChild = getResultRecursion(current->rightChild);
	}
	int result = makeOperation(current->data, leftChild, rightChild);
	return result;
}

int Set::makeOperation(char const operation, int const operand1, int const operand2) const
{
	if (operation == '+')
	{
		return operand1 + operand2;
	}
	else if (operation == '-')
	{
		return operand1 - operand2;
	}
	else if (operation == '*')
	{
		return operand1 * operand2;
	}
	else
	{
		return operand1 / operand2;
	}
}

void Set::addExpression(char * str)
{
	int i = 0;
	addExpressionRecursion(str, head, i);	
}

void Set::addExpressionRecursion(char * str, Node*& current, int iterator)
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
	else if (isNumber(str[iterator]))
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

void Set::addIfOperator(char* str, Node*& current, int iterator)
{
	if (current == nullptr)
	{
		addIfOperatorAndCurrentIsNullptr(str, current, iterator);
	}
	else if (current->leftChild == nullptr)
	{
		addIfOperatorAndCurrentLeftChildIsNullptr(str, current, iterator);
	}
	else
	{
		addIfOperatorAndCurrentRightChildIsNullptr(str, current, iterator);
	}
}

void Set::addIfOperatorAndCurrentIsNullptr(char* str, Node*& current, int iterator)
{
	int position = 0;
	current = new Node(str[iterator]);
	if (str[iterator + 1] == '(')
	{
		position = getPositionOfClosingBracket(str, iterator + 1);
		addExpressionRecursion(str, current, iterator + 2);
		addExpressionRecursion(str, current, position + 1);
	}
	else
	{
		addExpressionRecursion(str, current, iterator + 1);
		addExpressionRecursion(str, current, iterator + 2);
	}
}

void Set::addIfOperatorAndCurrentLeftChildIsNullptr(char* str, Node*& current, int iterator)
{
	int position = 0;
	current->leftChild = new Node(str[iterator]);
	current->leftChild->parent = current;
	if (str[iterator + 1] == '(')
	{
		position = getPositionOfClosingBracket(str, iterator);
		addExpressionRecursion(str, current->leftChild, iterator + 2);
		addExpressionRecursion(str, current->leftChild, position + 1);
	}
	else
	{
		addExpressionRecursion(str, current->leftChild, iterator + 1);
		addExpressionRecursion(str, current->leftChild, iterator + 2);
	}
}

void Set::addIfOperatorAndCurrentRightChildIsNullptr(char* str, Node*& current, int iterator)
{
	int position = 0;
	current->rightChild = new Node(str[iterator]);
	current->rightChild->parent = current;
	if (str[iterator + 1] == '(')
	{
		position = getPositionOfClosingBracket(str, iterator);
		addExpressionRecursion(str, current->rightChild, iterator + 2);
		addExpressionRecursion(str, current->rightChild, position + 1);
	}
	else
	{
		addExpressionRecursion(str, current->rightChild, iterator + 1);
		addExpressionRecursion(str, current->rightChild, iterator + 2);
	}
}

int Set::getPositionOfClosingBracket(char const * str, int iterator) const
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

bool Set::isOperator(char const symbol) const
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

bool Set::isNumber(char const symbol) const
{
	return symbol == '0' || symbol == '1' || symbol == '2' || symbol == '3' || symbol == '4' ||
			symbol == '5' || symbol == '6' || symbol == '7' || symbol == '8' || symbol == '9';
}