#pragma once

struct Node
{
	explicit Node(int data); // конструктор с параметром
	~Node(); // деструктор
	int data;
	Node* previous;
	Node* next;
private:
	Node(); // конструктор без параметров
};