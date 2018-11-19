#include "Node.h"
#include <fstream>
#include <iostream>

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

bool Node::operator<(CompareInterface const & c) const
{
	Node const element = static_cast<Node const &>(c);
	return this->data < element.data;
}