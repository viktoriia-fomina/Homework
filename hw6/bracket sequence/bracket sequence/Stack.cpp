#include "Stack.h"
#include "Element.h"

Stack::Stack()
{
	head = nullptr;
}

Stack::~Stack()
{
	auto* temp = head;
	while (!isEmpty())
	{
		temp = head;
		head = temp->next;
		temp->next = nullptr;
		delete temp;
		temp = nullptr;
	}
}

void Stack::push(char data)
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
	head = nullptr;
	head = temp;
	return true;
}

char Stack::peek() const
{
	if (!isEmpty())
	{
		return head->data;
	}
	else
	{
		cout << "Stack is empty\n";
		return '\0';
	}
}

bool Stack::isEmpty() const
{
	return head == nullptr;
}