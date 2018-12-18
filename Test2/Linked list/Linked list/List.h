#pragma once
#include <iostream>
#include "Node.h"

struct Node;

struct List
{
	List();
	~List();
	bool addToPosition(int const position, int const data);
	bool deleteFromThePosition(int const position);
	bool exists(int const data) const;
	friend std::ostream & operator<<(std::ostream & os, List const & l);
	bool isEmpty() const;
private:
	Node * operator[](int const index);
	Node * head;
	int numberOfElements;
};