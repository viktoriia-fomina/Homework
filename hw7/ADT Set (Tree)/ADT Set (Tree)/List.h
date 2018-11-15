#pragma once
#include <iostream>

using namespace std;

struct Element;

struct List
{
	List();

	~List();

	void addNode(int const data);

	bool deleteNode(int const data);

	void printInAscendingOrder() const;

	void printInDescendingOrder() const;

	bool isEmpty() const;

private:
	void deleteList();
	void deleteHead(int const data, Element* temp);
	void deleteElementThatIsNotHead(int const data, Element* temp);
	void swap(Element* a, Element* b);
	Element* head;
	Element* tail;
};