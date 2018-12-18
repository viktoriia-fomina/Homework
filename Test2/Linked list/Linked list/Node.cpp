#include "Node.h"

Node::Node(int const data)
{
	this->prev = nullptr;
	this->next = nullptr;
	this->data = data;
}