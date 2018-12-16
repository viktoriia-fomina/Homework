#pragma once
#include <string>
#include <iostream>

struct Node;

struct Set
{
	Set();

	~Set();

	void addValueByKey(std::string const & key, std::string const & value);

	std::string getValueByKey(std::string const & key);

	bool keyExists(std::string const & key) const;

	void deleteKeyAndItsValue(std::string const & key);

	void print() const;

private:
	void printRecursion(Node const * const current) const;

	void deleteRecursion(Node * current);

	void addIfKeyExists(std::string const & key, std::string const & value, Node * current);

	Node * addRecurson(std::string const & key, std::string const & value, Node * current);

	//Node & setValueByKey(std::string const & key);

	void balance(Node *  added);

	int lengthOfSubtree(Node * current, int count) const;

	void setBalance(Node * a, Node * b, Node * c);

	void rotateSmallLeft(Node * a, Node * b, Node * c);

	void rotateSmallRight(Node * a, Node * b, Node * c);

	void rotateLeft(Node * a, Node * b, Node * c);

	void rotateRight(Node * a, Node * b, Node * c);

	void getValueByKeyRecursion(std::string & value, std::string const & key, 
			Node const * const current);

	void keyExistsRecursion(bool & keyWasFound, std::string const & key, 
			Node const * const current) const;

	bool isEmpty() const;

private:
	Node* head;
};