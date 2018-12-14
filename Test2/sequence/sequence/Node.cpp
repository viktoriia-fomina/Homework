#include "Node.h"

Node::Node(int const data)
{
	this->number = 0;
	this->data = data;
	this->previous = nullptr;
	this->next = nullptr;
}