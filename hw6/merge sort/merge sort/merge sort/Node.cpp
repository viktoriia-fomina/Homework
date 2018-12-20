#include "Node.h"
#include "ForStrings.h"

using namespace std;

Node::Node(std::string const & data)
{
	this->firstWord = *firstPartOfStr(data);
	this->secondWord = *secondPartOfStr(data);
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

string Node::getWordNumbered(int const number) const
{
	if (number == 1)
	{
		return (*this).firstWord;
	}
	else
	{
		return (*this).secondWord;
	}
}