#pragma once

struct Node
{
	Node(int const data); // constructor
	~Node(); // destructor
	int data;
	Node* leftChild;
	Node* rightChild;
};