#pragma once

struct Node
{
	Node(int data);
	~Node();
	int data;
	Node* previous;
	Node* next;
};