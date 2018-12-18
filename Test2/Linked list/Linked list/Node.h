#pragma once

struct Node
{
	Node(int const data);

	int data;
	Node* next;
	Node* prev;
};