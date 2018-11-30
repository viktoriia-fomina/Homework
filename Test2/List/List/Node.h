#pragma once

struct Node
{
	explicit Node(int const data);

	bool operator==(Node const & node) const;
	bool operator!=(Node const & node) const;
	int data;
	Node* previous;
	Node* next;
};