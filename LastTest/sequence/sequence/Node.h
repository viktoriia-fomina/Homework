#pragma once

struct Node
{
	explicit Node(int const data);

	int number;
	int data;
	Node* previous;
	Node* next;
};