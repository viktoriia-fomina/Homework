#pragma once
#include <string>

struct Node
{
	explicit Node(std::string const & data);

	int number;
	std::string data;
	Node* previous;
	Node* next;
};