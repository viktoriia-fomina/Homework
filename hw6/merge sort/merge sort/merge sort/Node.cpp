#include "Node.h"
#include "ForStrings.h"
#include <cassert>

using namespace std;

Node::Node(std::string const & data)
{
	this->firstWord = firstPartOfStr(data);
	this->secondWord = secondPartOfStr(data);
	this->previous = nullptr;
	this->next = nullptr;
}

Node::Node(string const & firstWord, string const & secondWord)
{
	this->firstWord = firstWord;
	this->secondWord = secondWord;
	this->previous = nullptr;
	this->next = nullptr;
}

Node::Node()
{
	this->firstWord = '\0';
	this->secondWord = '\0';
	this->previous = nullptr;
	this->next = nullptr;
}

Node & Node::operator=(Node const & node)
{
	if (this != &node)
	{
		(*this).firstWord = node.firstWord;
		(*this).secondWord = node.secondWord;
	}
	return *this;
}

string Node::getWordNumbered(int const numberOfWord) const
{
	assert(numberOfWord == 1 || numberOfWord == 2);
	if (numberOfWord == 1)
	{
		return (*this).firstWord;
	}
	else
	{
		return (*this).secondWord;
	}
}

void Node::setWordNumbered(std::string strToSet, int const numberOfWord)
{
	assert(numberOfWord == 1 || numberOfWord == 2);
	if (numberOfWord == 1)
	{
		(*this).firstWord = strToSet;
	}
	else
	{
		(*this).secondWord = strToSet;
	}
}