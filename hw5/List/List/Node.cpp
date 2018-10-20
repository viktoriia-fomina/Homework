#include "Node.h"

Node::Node(int data)
{
	this->data = data;
	this->previous = nullptr;
	this->next = nullptr;
}

Node::Node() {}

Node::~Node()
{
	this->previous = nullptr;
	this->next = nullptr;
	data = 0;
}