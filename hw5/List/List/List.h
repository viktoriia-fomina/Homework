#pragma once
#include <iostream>
#include "Node.h"

struct Node;

struct List
{
	// конструкторы - деструкторы, добавление - удаление
	List();
	~List();
	void addNode(int const data); // 1
	int deleteNode(int const data); // 2
	// остальное
	friend std::ostream & operator<<(std::ostream & os, List const & list); // 3
	bool isEmpty() const;
private:
	void deleteList();
	void deleteHead(int const data, Node* temp);
	void deleteElementThatIsNotHead(int const data, Node* temp);
	void swap(Node * a, Node* b);
	Node* head;
};