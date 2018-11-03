#pragma once

struct Node
{
	Node(char const data); // constructor
	~Node(); // destructor
	char data;
	Node* leftChild;
	Node* rightChild;
	Node* parent;
};