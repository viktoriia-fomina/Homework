#pragma once
#include <string>

struct Node
{
	explicit Node(std::string const & data);

	Node();

	Node & operator=(Node const & node);

	std::string getWordNumbered(int const number) const;

	std::string firstWord;
	std::string secondWord;
	Node* previous;
	Node* next;
};