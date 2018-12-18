#include "List.h"
#include "Node.h"

using namespace std;

List::List()
{
	head = nullptr;
	numberOfElements = 0;
}

List::~List()
{
	while (!isEmpty())
	{
		auto* temp = head;
		head = head->next;
		delete temp;
	}
}

bool List::addToPosition(int const position, int const data)
{
	if (position < 0 || position > numberOfElements)
	{
		return false;
	}
	if (position == 0)
	{
		if (isEmpty())
		{
			head = new Node(data);
		}
		else
		{
			auto* lastHead = head;
			head = new Node(data);
			head->next = lastHead;
			lastHead->prev = head;
		}
	}
	else
	{
		if (position == numberOfElements)
		{
			auto* prevEl = (*this)[position - 1];
			prevEl ->next = new Node(data);
			prevEl->next->prev = prevEl;
		}
		else
		{
			auto* prevEl = (*this)[position - 1];
			auto* nextEl = (*this)[position];
			prevEl->next = new Node(data);
			prevEl->next->prev = prevEl;
			prevEl->next->next = nextEl;
			nextEl->prev = prevEl->next;
		}
	}
	++numberOfElements;
	return true;
}

bool List::deleteFromThePosition(int const position)
{
	if (isEmpty() || position < 0 || position >= numberOfElements)
	{
		return false;
	}
	if (position == 0)
	{
		auto* elementToDelete = head;
		head = head->next;
		delete elementToDelete;
	}
	else
	{
		auto* prev = (*this)[position - 1];
		auto* elementToDelete = prev->next;
		prev->next = elementToDelete->next;
		if (prev->next != nullptr)
		{
			prev->next->prev = prev;
		}
		delete elementToDelete;
	}
	--numberOfElements;
	return true;
}

ostream & operator<<(ostream & os, List const & l)
{
	Node* temp = l.head;
	while (temp != nullptr)
	{
		os << temp->data << " ";
		temp = temp->next;
	}
	return os;
}

bool List::isEmpty() const
{
	return head == nullptr;
}

Node * List::operator[](int const index)
{
	int i = 0;
	auto* temp = head;
	while (i < index && temp->next != nullptr)
	{
		temp = temp->next;
		++i;
	}
	return temp;
}

bool List::exists(int const data) const
{
	if (isEmpty())
	{
		return false;
	}
	auto* temp = head;
	while (temp->data != data || temp != nullptr)
	{
		if (temp->data == data)
		{
			return false;
		}
		temp = temp->next;
	}
	return false;
}