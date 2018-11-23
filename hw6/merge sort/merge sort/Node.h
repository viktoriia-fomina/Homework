#pragma once
#include <string>

struct Node
{
	explicit Node(std::string const & data);

	Node();
	bool operator<(Node const & node) const;
	Node & operator=(Node const & node);

	std::string data;
	Node* previous;
	Node* next;
};