#pragma once
#include <iostream>

using namespace std;

struct Element;

struct List
{
	List();
	~List();
	void addNode(int const data);
	void deleteNode(int const data);
	void printInAscendingOrder() const;
	void printInDescendingOrder() const;
	bool isEmpty() const;
private:
	void deleteHead(int const data, Element* temp);
	void deleteElementThatIsNotHead(int const data, Element* temp);
	void swap(Element* a, Element* b);
	Element* head;
};