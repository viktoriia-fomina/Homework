#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

struct Node;

struct List
{
	// конструкторы - деструкторы, добавление - удаление
	List();
	~List();
	void addNode(int data); // 1
	void deleteNode(int data); // 2
	// остальное
	friend ostream & operator<<(ostream & os, List const & list); // 3
private:
	void swap(Node * a, Node* b);
	Node* head;
};