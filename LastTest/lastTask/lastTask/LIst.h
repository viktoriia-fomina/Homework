#pragma once
#include <iostream>

struct Node;

struct List
{
	List();

	~List();

	void addElement(int const data);

	bool deleteElement(int const data);

	Node & operator[](int const index) const;

	int getData(int const index) const;

	int getNumOfNodes(int const index) const;

	friend std::ostream & operator<<(std::ostream & os, List const & list);

	bool isEmpty() const;

	int size() const;

	bool exists(int const data) const;

	void sort();

private:

	void deleteList();

	void deleteHead(int const data, Node* temp);

	void deleteElementThatIsNotHead(int const data, Node* temp);

	int sizeOfList;
	Node* head;
};