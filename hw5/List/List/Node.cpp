#include "Node.h"

Node::Node(int data)
{
	auto* newElement =  new Node;
	this->data = data;
	this->previous = nullptr;
	this->next = nullptr;
}

Node::Node()
{

}

Node::~Node()
{

}

int Node::getData() const
{
	return data;
}

void Node::setData(int data)
{
	this->data = data;
}