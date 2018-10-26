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

int Stack::pop()
{
	if (!isEmpty())
	{
		auto* temp = head->next;
		head->next = nullptr;
		delete head;
		head = nullptr;
		head = temp;
		return 0;
	}
	else
	{
		return -1;
	}
}

char Stack::peek()
{
	if (!isEmpty())
	{
		return head->data;
	}
	else
	{
		cout << "Stack is empty\n";
	}
}

bool Stack::isEmpty()
{
	return head == nullptr;
}