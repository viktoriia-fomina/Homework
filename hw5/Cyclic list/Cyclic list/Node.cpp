#include "Node.h"

// ����������� - ����������

Node::Node(int data = 0)
{
	this->data = data;
	next = nullptr;
}

Node::~Node() {}