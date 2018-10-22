#pragma once
#include <iostream>

using namespace std;

struct Node;

struct List
{
	List();
	~List();
	void addNode(int const data);
	void deleteNode(int const data);
	friend ostream & operator<<(ostream & os, List const & list);
private:
	bool isEmpty() const;
	bool ifTwoElements() const;
	void addNodeIfNextIsNotHead(int const data, Node * const newElement);
	void addNodeIfNextIsHead(int const data, Node * const newElement);
	void swap(Node * a, Node * b);
	Node* head;
};