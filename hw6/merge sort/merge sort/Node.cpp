#include "Node.h"

using namespace std;

Node::Node(std::string const & data)
{
	bool spaceWasFound = false;
	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i] == ' ')
		{
			spaceWasFound = true;
		}
		else if (!spaceWasFound)
		{
			firstWord += data[i];
		}
		else
		{
			secondWord += data[i];
		}
	}
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