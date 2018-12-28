#pragma once

struct Node
{
	explicit Node(int const data);

	int data;
	Node* previous;
	Node* next;
};