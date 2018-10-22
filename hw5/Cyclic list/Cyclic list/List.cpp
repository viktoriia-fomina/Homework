#include "List.h"
#include "Node.h"

List::List()
{
	head = nullptr;
}

List::~List()
{
	if (!isEmpty())
	{ 
		while (head != head->next)
		{
			bool flagIfTwoElements = ifTwoElements();
			auto* temp = head;
			auto* previousBeforeHead = head;
			while (previousBeforeHead->next != head)
			{
				previousBeforeHead = previousBeforeHead->next;
			}
			head = head->next;
			previousBeforeHead->next = head;
			temp->next = nullptr;
			delete temp;
			temp = nullptr;
			if (flagIfTwoElements)
			{
				head->next = head;
			}
		}
		head->next = nullptr;
		delete head;
		head = nullptr;
	}
}

bool List::ifTwoElements() const
{
	return head == head->next->next;
}

void List::addNode(int const data)
{
	auto* newElement = new Node(data);
	if (!isEmpty())
	{
		if (head != head->next)
		{
			addNodeIfNextIsNotHead(data, newElement);
		}
		else
		{
			addNodeIfNextIsHead(data, newElement);
		}
	}
	else
	{
		head = newElement;
		head->next = head;
	}
}

void List::addNodeIfNextIsNotHead(int const data, Node * const newElement)
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

void List::addNodeIfNextIsHead(int const data, Node * const newElement)
{
	auto* temp = head;
	head = newElement;
	head->next = temp;
	temp->next = head;
}

void List::deleteNode(int const data)
{
	if (isEmpty())
	{
		cout << "List has no node\n";
	}
	else
	{
		auto* temp = head;
		if (head->next == head)
		{
			if (head->data == data)
			{
				this->~List();
			}
			else
			{
				cout << "Node was not found\n";
			}
		}
		// lallala
	}
}

ostream & operator<<(ostream & os, List const & list)
{
	if (!list.isEmpty())
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
			cout << temp->data;
		}
	}
	return os;
}

bool List::isEmpty() const
{
	return head == nullptr;
}

void List::swap(Node * a, Node * b)
{
	int const c = a->data;
	a->data = b->data;
	b->data = c;
}