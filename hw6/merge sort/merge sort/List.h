#pragma once
#include <iostream>
#include "Sort.h"
#include <string>

struct Node;

struct List : Sort<Node, int>
{
	List();

	~List();

	void addNode(std::string const & data);

	int deleteNode(std::string const & data);

	Node & operator[](int const & index);
									
	friend std::ostream & operator<<(std::ostream & os, List const & list); 

	bool isEmpty() const;

private:
	void deleteList();

	void deleteHead(std::string const & data, Node* temp);

	void deleteElementThatIsNotHead(std::string const & data, Node* temp);

	Node* head;
};