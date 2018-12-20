#include "Node.h"

using namespace std;

Node::Node(std::string const & data)
{
	this->data = data;
	this->previous = nullptr;
	this->next = nullptr;
}

Node::Node()
{
	this->data = '\0';
	this->previous = nullptr;
	this->next = nullptr;
}

bool Node::operator<(Node const & node) const
{
	return this->data < node.data;
}

Node & Node::operator=(Node const & node)
{
	if (this != &node)
	{
		(*this).data = node.data;
	}
	return *this;
}