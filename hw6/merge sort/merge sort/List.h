#pragma once
#include <iostream>
#include "Node.h"
#include "Sort.h"

using namespace std;

struct Node;

struct List : Sort<Node, int>
{
	List(); // конструктор
	~List(); // деструктор
	void addNode(int const data); // добавить узел
	void deleteNode(int const data); // удалить узел
	bool isEmpty() const; // проверить является ли список пустым
	friend ostream & operator<<(ostream & os, List const & list); // оператор вывода
private:
	void deleteHead(int const data, Node* temp); // удаление головы
	void deleteElementThatIsNotHead(int const data, Node* temp); // удаление не головного элемента
	void swap(Node * a, Node* b); // метод своп
	Node* head;
};