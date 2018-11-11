#pragma once
#include <iostream>

struct Node;

struct List
{
	List();
	~List();
	void addNode(int const data);
	void deleteNode(int const data);
	bool isEmpty() const;
	bool isOneNode() const;
	friend std::ostream & operator<<(std::ostream & os, List const & list);
	Node* getHead() const;
private:
	void deleteNodeIfOneNode(int const data);
	void deleteNodeIfMoreThanOneNode(int const data);
	void deleteHeadNodeIfMoreThanOneNode(int const data);
	void deleteNotHeadNodeIfMoreThanOneNode(int const data);
	void addNodeIfWasMoreThanOneNode(Node * const newElement);
	void addNodeIfWasOneNode(Node * const newElement);
	Node* head;
	Node* tail;
};