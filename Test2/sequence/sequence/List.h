#pragma once
#include <iostream>

struct Node;

struct List
{
	List();

	~List();

	void addElement(int const data);

	int deleteElement(int const data);

	Node & operator[](int const index) const;

	friend std::ostream & operator<<(std::ostream & os, List const & list);

	bool isEmpty() const;

	int size() const;

	int numberOfElements() const;

	bool exists(int const data) const;

	void sort();

private:

	void deleteList();

	void deleteHead(int const data, Node* temp);

	void deleteElementThatIsNotHead(int const data, Node* temp);

	int numOfElements;
	int sizeOfList;
	Node* head;
};