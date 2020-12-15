#pragma once
#include <string>

struct Node
{
	explicit Node(std::string const & data);

	Node(std::string const & firstWord, std::string const & secondWord);

	Node();

	Node & operator=(Node const & node);

	std::string getWordNumbered(int const numberOfWord) const;
	void setWordNumbered(std::string strToSet, int const numberOfWord);

	std::string firstWord;
	std::string secondWord;
	Node* previous;
	Node* next;
};