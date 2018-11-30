#pragma once
#include <iostream>
#include <string>
#include "Node.h"

struct Node;

struct List
{
	List();

	~List();

	void addNode(int const data);

	int deleteNode(int const data);

	Node & operator[](int const index);

	friend std::ostream & operator<<(std::ostream & os, List const & list);

	bool isEmpty() const;

	int size() const;

private:
	void deleteList();

	void deleteHead(int const data, Node* temp);

	void deleteElementThatIsNotHead(int const data, Node* temp);

	int sizeOfList;
	Node* head;
};