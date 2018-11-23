#include "Stack.h"
#include "Element.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
	head = nullptr;
}

Stack::~Stack()
{
	while (!isEmpty())
	{
		auto* temp = head;
		head = temp->next;
		temp->next = nullptr;
		delete temp;
	}
}

void Stack::push(int data)
{
	auto* newElement = new Element(data);
	if (!isEmpty())
	{
		newElement->next = head;
	}
	head = newElement;
}

bool Stack::pop()
{
	if (isEmpty())
	{
		return false;
	}
	auto* temp = head->next;
	head->next = nullptr;
	delete head;
	head = temp;
	return true;
}

pair<bool, int> & Stack::peek(pair<bool, int> & p) const
{
	p.first = head->data;
	if (isEmpty())
	{
		p.first = false;
		cout << "Stack is empty" << endl;
		p.second = -1;
	}
	else
	{
		p.first = true;
		p.second = head->data;
	}
	return p;
}

bool Stack::isEmpty() const
{
	return head == nullptr;
}