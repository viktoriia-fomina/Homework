#pragma once
#include <iostream>
#include "Sort.h"
#include <string>
#include "Node.h"

struct Node;

struct List : Sort<Node, std::string, int>
{
	List();

	~List();

	void addNode(std::string const & firstWord, std::string const & secondWord);

	int deleteNode(std::string const & data);

	Node & operator[](int const & index);

	std::string operator()(int const & index, int const & numberOfWord);

	friend std::ostream & operator<<(std::ostream & os, List const & list);

	bool isEmpty() const;

	int size() const;

private:
	void deleteList();

	void deleteHead(Node* temp);

	void deleteElementThatIsNotHead(std::string const & data, Node* temp);

	int sizeOfList;
	Node* head;
};