#include "Set.h"
#include "Node.h"

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
		}
		else
		{
			node->rightChild = new Node(data);
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

int Set::maximum(Node const * const current)
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
		current = nullptr;
	}
	else if (current->leftChild == nullptr && current->rightChild != nullptr)
	{
		current = current->rightChild;
	}
	else
	{
		current = current->leftChild;
	}
	delete temp;
}

bool Set::exists(int const data)
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

bool Set::isEmpty()
{
	return head == nullptr;
}