#include "List.h"
#include "Element.h"
#include <iostream>

using namespace std;

List::List()
{
	head = nullptr;
	tail = nullptr;
}

List::~List()
{
	deleteList();
}

void List::deleteList()
{
	while (!isEmpty())
	{
		auto* temp = head;
		head = head->next;
		delete temp;
	}
}

void List::addNode(int const data)
{
	if (!isEmpty())
	{
		auto* temp = head;
		head = new Element(data);
		head->next = temp;
		head->previous = nullptr;
		head->next->previous = head;
		if (head == tail)
		{
			tail->previous = head;
		}
		auto* temporary = head;
		while (temporary != tail && temporary->data < temporary->next->data)
		{
			swap(temporary, temporary->next);
			temporary = temporary->next;
		}
	}
	else
	{
		head = new Element(data);
		tail = head;
	}
}

bool List::deleteNode(int const data)
{
	if (isEmpty())
	{
		cout << "List is empty. Node can not be deleted\n";
		return false;
	}
	auto* temp = head;
	while (temp != nullptr && temp->data != data)
	{
		temp = temp->next;
	}
	if (temp == nullptr)
	{
		cout << "Node was not found. Node can not be deleted\n";
		return false;
	}
	else
	{
		if (temp == head)
		{
			deleteHead(data, temp);
		}
		else
		{
			deleteElementThatIsNotHead(data, temp);
		}

	}
	return true;
}

void List::deleteHead(int const data, Element* temp)
{
	if (head->next != nullptr)
	{
		head = head->next;
		head->previous = nullptr;
		delete temp;
	}
	else
	{
		deleteList();
	}
}

void List::deleteElementThatIsNotHead(int const data, Element* temp)
{
	if (temp->next != nullptr)
	{
		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
		delete temp;
	}
	else
	{
		tail = tail->previous;
		tail->next = nullptr;
		delete temp;
	}
}

void List::printInDescendingOrder() const
{
	auto* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void List::printInAscendingOrder() const
{
	auto* temp = tail;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->previous;
	}
}

bool List::isEmpty() const
{
	return head == nullptr;
}

void List::swap(Element* a, Element* b)
{
	int const c = a->data;
	a->data = b->data;
	b->data = c;
}