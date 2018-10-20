#pragma once

struct Node
{
	explicit Node(int data);
	Node();
	~Node();
	int data;
	Node* previous;
	Node* next;
};