#pragma once
#include "CompareInterface.h"
#include <string>

struct Node : CompareInterface
{
	explicit Node(std::string const & data); // конструктор с параметром

	bool operator<(CompareInterface const & c2) const;

	std::string data;
	Node* previous;
	Node* next;
private:
	int compareTwoLetters(char const letter1, char const letter2) const;
};