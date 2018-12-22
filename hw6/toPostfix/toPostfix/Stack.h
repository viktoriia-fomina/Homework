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
	// добавление элемента в голову
	void push(char data);
	// удаление элемента из головы
	int pop();
	// посмотреть на головной элемент
	char peek();
	// проверяет является ли стек пустым
	bool isEmpty();
private:
	Element * head;
};