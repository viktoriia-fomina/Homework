#pragma once

struct Node
{
	explicit Node(int data);
	Node();
	~Node();
	int getData() const;
	void setData(int data);
	int data;
	Node* previous;
	Node* next;
};