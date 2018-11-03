#pragma once
struct Node;
struct Set
{
	Set();
	~Set();
	bool add(int const data);
	bool remove(int const data);
	bool exists(int const data);
	bool isEmpty();
private:
	void addNodeNotToHead(Node* node, int const data);
	void removeRecursion(Node* current, int const data);
	void removeIfChildIsNullptr(Node*& current);
	Node* maximum(Node * const current);
	Node* minimum(Node * const current);
	Node* head;
};