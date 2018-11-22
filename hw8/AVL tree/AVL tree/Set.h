#pragma once
#include <string>

struct Node;

struct Set
{
	void addValueByKey(std::string const & key, std::string const & value);
	std::string getValueByKey(std::string const & key);
	bool keyExists(std::string const & key) const;
	void deleteKeyAndItsValue(std::string const & key);
private:
	Node & setValueByKey(std::string const & key);
	void fixDifferenceBetweenHeights(Node const * const addedElement);
	void fixDifferenceBetweenHeightsRecursion(Node const * const current);
	void getValueByKeyRecursion(std::string & value, std::string const & key, Node const * const current);
	void keyExistsRecursion(bool & keyWasFound, std::string const & key, Node const * const current) const;
	bool isEmpty() const;

	Node* head;
};