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

int Stack::peek() const
{
	if (!isEmpty())
	{
		return head->data;
	}
	else
	{
		cout << "Stack is empty\n";
		return -1;
	}
}

bool Stack::isEmpty() const
{
	return head == nullptr;
}