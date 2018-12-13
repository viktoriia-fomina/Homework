#include "Node.h"

using namespace std;

Node::Node(std::string const & data)
{
	this->number = 0;
	this->data = data;
	this->previous = nullptr;
	this->next = nullptr;
}