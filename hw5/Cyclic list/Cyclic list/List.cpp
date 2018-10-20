#include "List.h"
#include "Node.h"

List::List()
{
	head = nullptr;
}

List::~List()
{
	if (head != nullptr)
	{
		while (head != head->next)
		{
			auto* temp = head;
			head = head->next;
			temp->next = nullptr;
			delete temp;
			temp = nullptr;
		}
	}
}

void List::addNode(int data)
{
	auto* newElement = new Node(data);
	if (head != nullptr)
	{
		if (head != head->next)
		{
			auto* temp = head;
			auto* lastHead = head;
			while (temp->next != head)
			{
				temp = temp->next;
			}
			head = newElement;
			head->next = lastHead;
			temp->next = head;
		}
		else
		{
			auto* temp = head;
			head = newElement;
			head->next = temp;
			temp->next = head;
		}
	}
	else
	{
		head = newElement;
		head->next = head;
	}
}

void List::deleteNode(int data)
{

}

ostream & operator<<(ostream & os, List const & list)
{
	if (list.head != nullptr)
	{
		if (list.head->next == list.head)
		{
			os << list.head->data;
		}
		else
		{
			auto* temp = list.head;
			while (temp->next != list.head)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
	}
	return os;
}

void List::swap(Node* a, Node* b)
{
	int const c = a->data;
	a->data = b->data;
	b->data = c;
}