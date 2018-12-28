#include "Node.h"

Node::Node(int const data)
{
	this->data = data;
	this->previous = nullptr;
	this->next = nullptr;
}