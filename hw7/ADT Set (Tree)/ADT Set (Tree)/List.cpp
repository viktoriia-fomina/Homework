#include "List.h"
#include "Element.h"

List::List()
{
	head = nullptr;
}

List::~List()
{
	while (!isEmpty())
	{
		auto* temp = head;
		head = head->next;
		temp->next = nullptr;
		temp->previous = nullptr;
		delete temp;
		temp = nullptr;
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
		auto* temporary = head;
		while (temporary->next != nullptr && temporary->data < temporary->next->data)
		{
			swap(temporary, temporary->next);
			temporary = temporary->next;
		}
	}
	else
	{
		head = new Element(data);
	}
}

void List::deleteNode(int const data)
{
	if (isEmpty())
	{
		cout << "List is empty. Node can not be deleted\n";
	}
	else
	{
		auto* temp = head;
		while (temp != nullptr && temp->data != data)
		{
			temp = temp->next;
		}
		if (temp == nullptr)
		{
			cout << "Node was not found. Node can not be deleted\n";
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
	}
}

void List::deleteHead(int const data, Element* temp)
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
		this->~List();
	}
}

void List::deleteElementThatIsNotHead(int const data, Element* temp)
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

void List::printInAscendingOrder() const
{
	auto* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void List::printInDescendingOrder() const
{
	auto* temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
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