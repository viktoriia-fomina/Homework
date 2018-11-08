#pragma once

struct Node
{
	explicit Node(char const data); // constructor
	char data;
	Node* leftChild;
	Node* rightChild;
	Node* parent;
};