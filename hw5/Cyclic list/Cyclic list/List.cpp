#include "List.h"
#include "Node.h"

List::List()
{
	head = nullptr;
}

List::~List()
{
	while (head != nullptr)
	{
		auto* temp = head;
		head = head->next;
		head->next = nullptr;
		delete head;
		head = nullptr;
	}
}

void List::addNode(int data)
{

}

void List::deleteNode(int data)
{

}

void List::swap(Node* a, Node* b)
{
	int const c = a->data;
	a->data = b->data;
	b->data = c;
}