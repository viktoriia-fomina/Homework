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
	void deleteNodeIfOneNode(int const data);
	void deleteNodeIfMoreThanOneNode(int const data);
	void deleteHeadNodeIfMoreThanOneNode(int const data);
	void deleteNotHeadNodeIfMoreThanOneNode(int const data);
	void addNodeIfNextIsNotHead(int const data, Node * const newElement);
	void addNodeIfNextIsHead(int const data, Node * const newElement);
	void swap(Node * a, Node * b);
	Node* head;
};