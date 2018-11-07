#include "List.h"
#include "Node.h"

using namespace std;

// конструктор - деструктор

List::List()
{
	head = nullptr;
}

List::~List()
{
	if (!isEmpty())
	{ 
		auto* oldHead = head;
		head = head->next;
		auto* temp = head->next;
		while (temp != oldHead)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
		delete head;
	}
}

// добавление элемента

void List::addNode(int const data)
{
	auto* newElement = new Node(data);
	if (!isEmpty())
	{
		if (!ifOneNode())
		{
			addNodeIfNextIsNotHead(newElement);
		}
		else
		{
			addNodeIfNextIsHead(newElement);
		}
	}
	else
	{
		head = newElement;
		head->next = head;
	}
}

void List::addNodeIfNextIsNotHead( Node * const newElement)
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

void List::addNodeIfNextIsHead( Node * const newElement)
{
	auto* temp = head;
	head = newElement;
	head->next = temp;
	temp->next = head;
}

// удаление элемента

void List::deleteNode(int const data)
{
	if (isEmpty())
	{
		cout << "List is empty. Node can not be deleted\n";
	}
	else
	{
		if (ifOneNode())
		{
			deleteNodeIfOneNode(data);
		}
		else
		{
			deleteNodeIfMoreThanOneNode(data);
		}
	}
}

void List::deleteNodeIfOneNode(int const data)
{
	if (head->data == data)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		cout << "Node was not found. Node can not be deleted\n";
	}
}

void List::deleteNodeIfMoreThanOneNode(int const data)
{
	if (head->data == data)
	{
		deleteHeadNodeIfMoreThanOneNode(data);
	}
	else
	{
		deleteNotHeadNodeIfMoreThanOneNode(data);
	}
}

void List::deleteHeadNodeIfMoreThanOneNode(int const data)
{
	auto* temp = head;
	auto* prevBeforeHead = head;
	while (prevBeforeHead->next != head)
	{
		prevBeforeHead = prevBeforeHead->next;
	}
	head = head->next;
	prevBeforeHead->next = head;
	temp->next = nullptr;
	delete temp;
	temp = nullptr;
}

void List::deleteNotHeadNodeIfMoreThanOneNode(int const data)
{
	auto* temp = head;
	while (temp->data != data && temp->next != head)
	{
		temp = temp->next;
	}
	if (temp->data == data)
	{
		auto* prevBeforeElementToDelete = temp;
		while (prevBeforeElementToDelete->next != temp)
		{
			prevBeforeElementToDelete = prevBeforeElementToDelete->next;
		}
		prevBeforeElementToDelete->next = temp->next;
		temp->next = nullptr;
		delete temp;
		temp = nullptr;
	}
	else
	{
		cout << "Node was not found. Node can not be deleted\n";
	}
}

// проверка является ли список пустым

bool List::isEmpty() const
{
	return head == nullptr;
}

// проверка один ли элемент в списке

bool List::ifOneNode() const
{
	return head == head->next;
}

// оператор вывода

ostream & operator<<(ostream & os, List const & list)
{
	if (!list.isEmpty())
	{
		if (list.ifOneNode())
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

Node* List::getHead() const
{
	return head;
}