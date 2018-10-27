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
	void push(int data);
	// удаление элемента из головы
	int pop();
	// посмотреть на головной элемент
	int peek();
	// проверяет является ли стек пустым
	bool isEmpty();
private:
	Element * head;
};