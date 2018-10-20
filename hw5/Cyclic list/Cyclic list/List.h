#pragma once

struct Node;

struct List
{
	List();
	~List();
	void addNode(int data);
	void deleteNode(int data);
private:
	void swap(Node* a, Node* b);
	Node* head;
};