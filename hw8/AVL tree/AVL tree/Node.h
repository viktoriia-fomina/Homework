#pragma once
#include <string>

struct Node
{
	Node(std::string const & key, std::string const & value);

	std::string key; // нельз€ хранить значени€ с 2 одинаковыми ключами
	std::string value;
	int balanceFactor;
	Node* parent;
	Node* leftChild;
	Node* rightChild;
};