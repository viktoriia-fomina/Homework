#pragma once

struct Node
{
	Node(int const data); // constructor

	int data;
	Node* leftChild;
	Node* rightChild;
};