#pragma once
#include <utility>

struct Element;

struct Stack
{
	// конструктор
	Stack();

	// деструктор
	~Stack();

	// добавление элемента в голову
	void push(int data);

	// удаление элемента из головы
	bool pop();

	// посмотреть на головной элемент
	std::pair<bool, int> peek(std::pair<bool, int> & p) const;

	// проверяет является ли стек пустым
	bool isEmpty() const;
private:
	Element * head;
};