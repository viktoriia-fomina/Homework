#pragma once

struct Node
{
	Node(int data);
	~Node();
	int data;
	Node* next;
};