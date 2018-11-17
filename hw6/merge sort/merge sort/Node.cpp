#include "Node.h"
#include <fstream>
#include <iostream>

using namespace std;

Node::Node(std::string const & data)
{
	this->data = data;
	this->previous = nullptr;
	this->next = nullptr;
}

bool Node::operator<(CompareInterface const & c) const
{
	Node const element = static_cast<Node const &>(c);
	size_t const size1 = this->data.size();
	size_t const size2 = element.data.size();
	size_t minSize;
	if (size1 < size2)
	{
		minSize = size1;
	}
	else
	{
		minSize = size2;
	}
	for (size_t i = 0; i < minSize; ++i)
	{
		if (compareTwoLetters(this->data[i], element.data[i]) == -2)
		{
			cout << "Error" << endl;
			return false;
		}
		else if (compareTwoLetters(this->data[i], element.data[i]) == 1)
		{
			return true;
		}
		else if (compareTwoLetters(this->data[i], element.data[i]) == -1)
		{
			return false;
		}
	}
	if (size1 == size2)
	{
		return false;
	}
	if (size1 < size2)
	{
		return true;
	}
	return false;
}

int Node::compareTwoLetters(char const letter1, char const letter2) const
{
	ifstream file("sort.txt", ios::in);
	if (!file.is_open())
	{
		cout << "File not found" << endl;
		return -2;
	}
	if (letter1 == letter2)
	{
		return 0;
	}
	char buffer = '\0';
	while (!file.eof() && (buffer != letter1 || buffer != letter2))
	{
		file >> buffer;
		cout << buffer << endl;
	}
	if (buffer == letter1)
	{
		return 1;
	}
	if (buffer == letter2)
	{
		return -1;
	}
	return -2;	
}