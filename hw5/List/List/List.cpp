#include "List.h"
#include "Node.h"

using namespace std;

// конструкторы - деструкторы, добавление - удаление

List::List()
{
	head = nullptr;
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

void List::addNode(int const data) // 1
{
	if (!isEmpty())
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

int List::deleteNode(int const data) // 2
{
	if (isEmpty())
	{
		cout << "List is empty. Node can not be deleted\n";
		return -1;
	}
	auto* temp = head;
	while (temp != nullptr && temp->data != data)
	{
		temp = temp->next;
	}
	if (temp == nullptr)
	{
		cout << "Node was not found. Node can not be deleted\n";
		return -1;
	}
	if (temp == head)
	{
		deleteHead(data, temp);
	}
	else
	{
		deleteElementThatIsNotHead(data, temp);
	}
	return 0;
}

void List::deleteHead(int const data, Node* temp)
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
		deleteList();
	}
}

void List::deleteElementThatIsNotHead(int const data, Node* temp)
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

// остальное

ostream & operator<<(ostream & os, List const & list) // 3
{
	auto* temp = list.head;
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

void List::swap(Node* a, Node* b)
{
	int const c = a->data;
	a->data = b->data;
	b->data = c;
}