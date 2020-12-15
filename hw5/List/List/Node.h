#pragma once

struct Node
{
	explicit Node(int data);
	int data;
	Node* previous;
	Node* next;
};