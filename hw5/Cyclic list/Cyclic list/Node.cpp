#include "Node.h"

// конструктор - деструктор

Node::Node(int data = 0)
{
	this->data = data;
	previous = nullptr;
	next = nullptr;
}

Node::~Node() {}