#include "Set.h"
#include "Node.h"
#include "List.h"
#include <fstream>

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

bool Set::add(char const data)
{
	if (isEmpty())
	{
		head = new Node(data);
	}
	else
	{
		if (exists(data))
		{
			return false;
		}
		addNodeNotToHead(head, data);
	}
	return true;
}

void Set::addNodeNotToHead(Node* node, char const data)
{
	if (node->data > data && node->leftChild != nullptr)
	{
		addNodeNotToHead(node->leftChild, data);
	}
	else if (node->data < data && node->rightChild != nullptr)
	{
		addNodeNotToHead(node->rightChild, data);
	}
	else
	{
		if (node->data > data)
		{
			node->leftChild = new Node(data);
			node->leftChild->parent = node;
		}
		else
		{
			node->rightChild = new Node(data);
			node->rightChild->parent = node;
		}
	}
}

bool Set::exists(char const data) const
{
	if (isEmpty())
	{
		return false;
	}
	auto* temp = head;
	bool flagIfExists = false;
	existsRecursion(data, head, flagIfExists);
	return flagIfExists;
}

void Set::existsRecursion(char const data, Node const * const current, bool & exists) const
{
	if (current->data == data)
	{
		exists = true;
	}
	if (current->leftChild != nullptr)
	{
		existsRecursion(data, current->leftChild, exists);
	}
	if (current->rightChild != nullptr)
	{
		existsRecursion(data, current->rightChild, exists);
	}
}

bool Set::isEmpty() const
{
	return head == nullptr;
}

void Set::treeTraversal(List & l) const
{
	if (!isEmpty())
	{
		treeTraversalRecursion(head, l);
	}
}

void Set::treeTraversalRecursion(Node const * current, List & l) const
{
	l.addNode(current->data);
	if (current->leftChild != nullptr)
	{
		treeTraversalRecursion(current->leftChild, l);
	}
	if (current->rightChild != nullptr)
	{
		treeTraversalRecursion(current->rightChild, l);
	}
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

bool Set::printInAscendingOrder() const
{
	List l;
	treeTraversal(l);
	if (l.isEmpty())
	{
		return false;
	}
	l.printInAscendingOrder();
	return true;
}

bool Set::printInDescendingOrder() const
{
	List l;
	treeTraversal(l);
	if (l.isEmpty())
	{
		return false;
	}
	l.printInDescendingOrder();
	return true;
}

int Set::readInfoFromFile()
{
	fstream file("data.txt", ios::in);
	if (!file.is_open())
	{
		cout << "File not found" << endl;
		return -1;
	}
	int const size = 100;
	char* buffer = new char[size] {};
	while (!file.eof())
	{
		file.getline(buffer, size);
		addExpression(buffer);
	}
	file.close();
	delete[] buffer;
	return 0;
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
	int position = 0;
	if (current == nullptr)
	{
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
	else if (current->leftChild == nullptr)
	{
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
	else
	{
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