#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

struct Node;

struct List
{
	List();
	~List();
	void addNode(int const data);
	void deleteNode(int const data);
									 // îñòàëüíîå
	bool isEmpty() const;
	friend ostream & operator<<(ostream & os, List const & list); // 3
private:
	void deleteHead(int const data, Node* temp);
	void deleteElementThatIsNotHead(int const data, Node* temp);
	void swap(Node * a, Node* b);
	Node* head;
};