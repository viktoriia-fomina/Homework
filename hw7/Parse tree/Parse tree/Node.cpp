#include "Node.h"

Node::Node(char const data)
{
	this->data = data;
	this->leftChild = nullptr;
	this->rightChild = nullptr;
	this->parent = nullptr;
}

Node::~Node()
{
	this->data = '\0';
	this->leftChild = nullptr;
	this->rightChild = nullptr;
	this->parent = nullptr;
}