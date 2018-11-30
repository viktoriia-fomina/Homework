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
		return addIfKeyExists(key, value, current->leftChild);
	}
	else
	{
		return addIfKeyExists(key, value, current->rightChild);
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

void Set::balance(Node * added)
{
	if (added->parent->parent == nullptr)
	{
		return;
	}
	auto* current = added->parent->parent;
	auto* prev = added->parent;
	auto* prevPrev = added;
	int lengthL = 0;
	int lengthR = 0;
	while (current != head)
	{
		if (current->leftChild != nullptr)
		{
			lengthL = lengthOfSubtree(current->leftChild);
		}
		if (current->rightChild != nullptr)
		{
			lengthR = lengthOfSubtree(current->rightChild);
		}
		int balanceFactor = lengthR - lengthL;
		current->balanceFactor = balanceFactor;
		if (abs(balanceFactor) == 2)
		{
			setBalance(current, prev, prevPrev);
			return;
		}
		prevPrev = prev;
		prev = current;
		current = current->parent;
	}
}

int Set::lengthOfSubtree(Node * added) const
{
	int left = 0;
	int right = 0;
	if (added->leftChild != nullptr)
	{
		left = lengthOfSubtree(added->leftChild);
	}
	else
	{
		left = -1;
	}
	if (added->rightChild != nullptr)
	{
		right = lengthOfSubtree(added->rightChild);
	}
	else
	{
		right = -1;
	}
	int max = left > right ? left : right;
	return max + 1;
}

void Set::setBalance(Node * a, Node * b, Node * c)
{
	if (a->leftChild == b && b->leftChild == c)
	{
		rotateSmallLeft(a, b, c);
		// расставить баланс факторы
	}
	else if (a->rightChild == b && b->rightChild == c)
	{
		rotateSmallRight(a, b, c);
		// расставить баланс факторы
	}
	else if (a->leftChild == b && b->rightChild == c)
	{
		rotateRight(a, b, c);
		// расставить баланс факторы
	}
	else
	{
		rotateLeft(a, b, c);
		// расставить баланс факторы
	}
}

void Set::rotateSmallLeft(Node * a, Node * b, Node * c)
{
	b->parent = a->parent;
	if (a->parent != nullptr)
	{
		if (a->parent->leftChild == a)
		{
			a->parent->leftChild = b;
		}
		else
		{
			a->parent->leftChild = b;
		}
	}
	a->rightChild = b->leftChild;
	if (b->leftChild != nullptr)
	{
		b->leftChild->parent = a;
	}
	b->leftChild = a;
	a->parent = b;
}

void Set::rotateSmallRight(Node * a, Node * b, Node * c)
{
	b->parent = a->parent;
	if (a->parent != nullptr)
	{
		if (a->parent->leftChild == a)
		{
			a->parent->leftChild = b;
		}
		else
		{
			a->parent->rightChild = b;
		}
	}
	a->leftChild = b->rightChild;
	if (b->rightChild != nullptr)
	{
		b->rightChild->parent = a;
	}
	b->rightChild = a;
	a->parent = b;
}

void Set::rotateLeft(Node * a, Node * b, Node * c)
{

}

void Set::rotateRight(Node * a, Node * b, Node * c)
{
	c->parent = a->parent;
	if (a->parent != nullptr)
	{
		if (a->parent->leftChild == a)
		{
			a->parent->leftChild = c;
		}
		else
		{
			a->parent->rightChild = c;
		}
		b->rightChild = c->leftChild;
		if (c->leftChild != nullptr)
		{
			c->leftChild->parent = b;
		}
		c->leftChild = b;
		b->parent = c;
		a->leftChild = c->rightChild;
		if (c->rightChild != nullptr)
		{
			c->rightChild->parent = a;
		}
		c->rightChild = a;
		a->parent = c;
	}
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