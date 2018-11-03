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
		// delete left subtree
		while (head->leftChild != nullptr)
		{
			remove(maximum(head->leftChild));
		}
		// delete right subtree
		while (head->rightChild != nullptr)
		{
			remove(maximum(head->rightChild));
		}
		delete head;
		head = nullptr;
	}
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

bool Set::remove(char const data)
{
	if (!exists(data))
	{
		return false;
	}
	removeRecursion(head, data);
	return true;
}

void Set::removeRecursion(Node*& current, char const data)
{
	if (current->data > data)
	{
		removeRecursion(current->leftChild, data);
	}
	else if (current->data < data)
	{
		removeRecursion(current->rightChild, data);
	}
	else
	{
		if (current->leftChild == nullptr || current->rightChild == nullptr)
		{
			removeIfChildIsNullptr(current);
			return;
		}
		else
		{
			current->data = maximum(current->leftChild);
			removeRecursion(current->leftChild, current->data);
		}
	}
}

int Set::maximum(Node const * const current) const
{
	auto* temp = current;
	while (temp->rightChild != nullptr)
	{
		temp = temp->rightChild;
	}
	return temp->data;
}

void Set::removeIfChildIsNullptr(Node*& current)
{
	auto* temp = current;
	if (current->leftChild == nullptr && current->rightChild == nullptr)
	{
		current->parent = nullptr;
		current = nullptr;
	}
	else if (current->leftChild == nullptr && current->rightChild != nullptr)
	{
		current = current->rightChild;
		current->parent = temp->parent;
	}
	else
	{
		current = current->leftChild;
		current->parent = temp->parent;
	}
	delete temp;
}

bool Set::exists(char const data) const
{
	if (isEmpty())
	{
		return false;
	}
	auto* temp = head;
	while (true)
	{
		if (temp->data > data)
		{
			if (temp->leftChild == nullptr)
			{
				return false;
			}
			temp = temp->leftChild;
		}
		else if (temp->data < data)
		{
			if (temp->rightChild == nullptr)
			{
				return false;
			}
			temp = temp->rightChild;
		}
		else
		{
			return true;
		}
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

void Set::addExpression(char const * str)
{
	int i = 0;
	int const size = strlen(str);
	
}

void Set::addExpressionRecursion(char * str, Node* current, int & iterator)
{
	if (isOperator)
	{
		addIfOperator(str, current, iterator);
	}
}

void Set::addIfOperator(char* str, Node* current, int & iterator)
{
	if (current->leftChild == nullptr)
	{
		current->leftChild = new Node(str[iterator]);
		current->leftChild->parent = current;
		++iterator;
		if (str[i])
		addExpressionRecursion();
		addExpressionRecursion();
	}
	else
	{
		current->rightChild = new Node(str[iterator]);
		current->leftChild->parent = current;
		++iterator;
		addExpressionRecursion();
		addExpressionRecursion();
	}
}

int Set::getPositionOfClosingBrake(char const * str) const
{

}

bool Set::isOperator(char const symbol) const
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}