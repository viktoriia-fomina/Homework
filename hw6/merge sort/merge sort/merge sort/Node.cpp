#include "Node.h"
#include "ForStrings.h"
#include <cassert>

using namespace std;

Node::Node(std::string const & data) : Node()
{
	this->firstWord = firstPartOfStr(data);
	this->secondWord = secondPartOfStr(data);
}

Node::Node(string const & firstWord, string const & secondWord) : Node()
{
	this->firstWord = firstWord;
	this->secondWord = secondWord;
}

Node::Node()
{
	this->previous = nullptr;
	this->next = nullptr;
	this->firstWord = '\0';
	this->secondWord = '\0';
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