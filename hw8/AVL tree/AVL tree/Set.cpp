#include "Set.h"
#include "Node.h"

void Set::addValueByKey(std::string const & key, std::string const & value)
{
	if (isEmpty())
	{
		head->key = key;
		head->value = value;
		return;
	}
	bool ifKeyExists = keyExists(key);
	if (ifKeyExists)
	{
		addIfKeyExists(key, value, head);
		return;
	}
	auto* temp = head;
	
	
	// дальше разобраться с балансом
}

Node & Set::addIfKeyExists(std::string const & key, std::string const & value, Node *& current)
{
	if (key == current->key)
	{
		current->value = value;
	}
	else if (key < current->key)
	{
		addIfKeyExists(key, value, current->leftChild);
	}
	else
	{
		addIfKeyExists(key, value, current->rightChild);
	}
}

Node *& Set::addRecurson(std::string const & key, std::string const & value, Node *& current)
{
	if (key < current->key)
	{
		if (current->leftChild != nullptr)
		{
			addRecurson(key, value, current);
		}
		else
		{
			current->leftChild = new Node(key, value);
			return current->leftChild;
		}
	} 
	else
	{
		if (current->rightChild != nullptr)
		{
			addRecurson(key, value, current);
		}
		else
		{
			current->rightChild = new Node(key, value);
			return current->rightChild;
		}
	}
}

void Set::balance()
{

}

void Set::

void Set::fixDifferenceBetweenHeights(Node const * const addedElement)
{
	fixDifferenceBetweenHeightsRecursion(addedElement);
}

void Set::fixDifferenceBetweenHeightsRecursion(Node const * const current)
{

}

std::string Set::getValueByKey(std::string const & key)
{
	std::string value;
	if (isEmpty())
	{
		return value;
	}
	getValueByKeyRecursion(value, key, head);
	return value;
}

void Set::getValueByKeyRecursion(std::string & value, std::string const & key, Node const * const current)
{
	if (current->key == key)
	{
		value = current->value;
		return;
	}
	if (current->leftChild != nullptr)
	{
		getValueByKeyRecursion(value, key, current->leftChild);
	}
	if (current->rightChild != nullptr)
	{
		getValueByKeyRecursion(value, key, current->rightChild);
	}
}

bool Set::keyExists(std::string const & key) const
{
	if (isEmpty())
	{
		return false;
	}
	bool keyWasFound = false;
	keyExistsRecursion(keyWasFound, key, head);
	return keyWasFound;
}

void Set::keyExistsRecursion(bool & keyWasFound, std::string const & key, Node const * const current) const
{
	if (current->key == key)
	{
		keyWasFound = true;
		return;
	}
	if (current->leftChild != nullptr)
	{
		keyExistsRecursion(keyWasFound, key, current->leftChild);
	}
	if (current->rightChild != nullptr)
	{
		keyExistsRecursion(keyWasFound, key, current->rightChild);
	}
}

bool Set::isEmpty() const
{
	return head == nullptr;
}

void Set::deleteKeyAndItsValue(std::string const & key)
{

}

Node & Set::setValueByKey(std::string const & key)
{
	//while
}