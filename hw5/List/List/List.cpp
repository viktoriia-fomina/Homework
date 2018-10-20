#include "List.h"
#include "Node.h"

// конструкторы - деструкторы, добавление - удаление

List::List()
{
	head = nullptr;
}

List::~List()
{
	if (head != nullptr)
	{
		while (head != nullptr)
		{
			auto* temp = head;
			head = head->next;
			temp->next = nullptr;
			temp->previous = nullptr;
			delete temp;
			temp = nullptr;
		}
	}
}

void List::addNode(int data) // 1
{
	if (head != nullptr)
	{
		auto* temp = head;
		head = new Node(data);
		head->next = temp;
		head->previous = nullptr;
		head->next->previous = head;
		auto* temporary = head;
		while (temporary->next != nullptr && temporary->data < temporary->next->data)
		{
			swap(temporary, temporary->next);
			temporary = temporary->next;
		}
	}
	else
	{
		head = new Node(data);
	}
}

void List::deleteNode(int data) // 2
{
	auto* temp = head;
	while (temp != nullptr && temp->data != data)
	{
		temp = temp->next;
	}
	if (temp == nullptr)
	{
		cout << "Element was not deleted because was not found\n";
	}
	else
	{
		// удаляем head
		if (temp == head)
		{
			if (head->next != nullptr)
			{
				head = head->next;
				head->previous = nullptr;
				temp->next = nullptr;
				delete temp;
				temp = nullptr;
			}
			else
			{
				List::~List();
			}
		}
		else // все остальные случаи
		{
			if (temp->next != nullptr)
			{
				temp->previous->next = temp->next;
				temp->next->previous = temp->previous;
				temp->previous = nullptr;
				temp->next = nullptr;
				delete temp;
				temp = nullptr;
			}
			else
			{
				temp->previous->next = nullptr;
				temp->previous = nullptr;
				delete temp;
				temp = nullptr;
			}
		}

	}
}

// остальное

ostream & operator<<(ostream & os, List const & list) // 3
{
	auto* temp = list.head;
	while (temp != nullptr)
	{
		os << (int)temp->data << " ";
		temp = temp->next;
	}
	return os;
}

void List::swap(Node* a, Node* b)
{
	int const c = a->data;
	a->data = b->data;
	b->data = c;
}