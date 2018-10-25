#pragma once
#include <iostream>

using namespace std;

struct Node;

struct List
{
	List();
	~List();
	int josephusProblem(int const numberOfWarriors, int const murderFrequency);
	void addNode(int const data);
	void deleteNode(int const data);
	bool isEmpty() const;
	friend ostream & operator<<(ostream & os, List const & list);
private:
	bool ifOneNode() const;
	void deleteNodeIfOneNode(int const data);
	void deleteNodeIfMoreThanOneNode(int const data);
	void deleteHeadNodeIfMoreThanOneNode(int const data);
	void deleteNotHeadNodeIfMoreThanOneNode(int const data);
	void addNodeIfNextIsNotHead(int const data, Node * const newElement);
	void addNodeIfNextIsHead(int const data, Node * const newElement);
	Node* head;
};