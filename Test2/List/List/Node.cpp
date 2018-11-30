#include "Node.h"

using namespace std;

Node::Node(int const data)
{
	this->data = data;
	this->previous = nullptr;
	this->next = nullptr;
}

bool Node::operator==(Node const & node) const
{
	return this->data == node.data;
}

bool Node::operator!=(Node const & node) const
{
	return this->data != node.data;
}

