#pragma once
#include <iostream>

using namespace std;

struct Node;

struct List
{
	List();
	~List();
	void addNode(int data);
	void deleteNode(int data);
	friend ostream & operator<<(ostream & os, List const & list);
private:
	void swap(Node* a, Node* b);
	Node* head;
};