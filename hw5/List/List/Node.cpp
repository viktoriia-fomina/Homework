#include "Node.h"

Node::Node(int data = 0)
{
	this->data = data;
	this->previous = nullptr;
	this->next = nullptr;
}

Node::~Node()
{
	this->previous = nullptr;
	this->next = nullptr;
	data = 0;
}