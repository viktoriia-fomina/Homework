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

bool Set::add(int const data)
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

void Set::addNodeNotToHead(Node* node, int const data)
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

bool Set::remove(int const data)
{
	if (!exists(data))
	{
		return false;
	}
	removeRecursion(head, data);
	return true;
}

void Set::removeRecursion(Node*& current, int const data)
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

bool Set::exists(int const data) const
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