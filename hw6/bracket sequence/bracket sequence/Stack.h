#pragma once
#include <iostream>

using namespace std;

struct Element;

struct Stack
{
	// конструктор
	Stack();
	// деструктор
	~Stack();
	// конструктор копирования

	// оператор присваивания

	// добавление элемента в голову
	void push(char data);
	// удаление элемента из головы
	bool pop();
	// посмотреть на головной элемент
	char peek() const;
	// проверяет является ли стек пустым
	bool isEmpty() const;
private:
	Element* head;
};