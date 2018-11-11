#include "List.h"
#include "Node.h"

using namespace std;

// конструктор - деструктор

List::List()
{
	head = nullptr;
	tail = nullptr;
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
		if (!isOneNode())
		{
			addNodeIfWasMoreThanOneNode(newElement);
		}
		else
		{
			addNodeIfWasOneNode(newElement);
		}
	}
	else
	{
		head = newElement;
		tail = head;
		head->next = head;
	}
}

void List::addNodeIfWasMoreThanOneNode(Node * const newElement)
{
	auto* lastHead = head;
	head = newElement;
	head->next = lastHead;
	tail->next = head;
}

void List::addNodeIfWasOneNode(Node * const newElement)
{
	auto* temp = head;
	head = newElement;
	head->next = temp;
	tail->next = head;
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
		if (isOneNode())
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
		tail = nullptr;
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
	auto* lastHead = head;
	head = lastHead->next;
	tail->next = head;
	delete lastHead;
}

void List::deleteNotHeadNodeIfMoreThanOneNode(int const data)
{
	auto* prevBeforeElementToDelete = head;
	if (head->next->data == data && head->next == tail)
	{
		auto* elementToDelete = tail;
		head->next = head;
		tail = head;
		delete elementToDelete;
	}
	else
	{
		while (prevBeforeElementToDelete->next->data != data && prevBeforeElementToDelete->next != head)
		{
			prevBeforeElementToDelete = prevBeforeElementToDelete->next;
		}
		if (prevBeforeElementToDelete->next->data == data)
		{
			if (prevBeforeElementToDelete->next == tail)
			{
				auto* lastTail = tail;
				tail = prevBeforeElementToDelete;
				tail->next = head;
				delete lastTail;
			}
			else
			{
				auto* elementToDelete = prevBeforeElementToDelete->next;
				prevBeforeElementToDelete->next = elementToDelete->next;
				delete elementToDelete;
			}
		}
		else
		{
			cout << "Node was not found. Node can not be deleted\n";
		}
	}
}

// проверка является ли список пустым

bool List::isEmpty() const
{
	return head == nullptr;
}

// проверка один ли элемент в списке

bool List::isOneNode() const
{
	return head == head->next;
}

// оператор вывода

ostream & operator<<(ostream & os, List const & list)
{
	if (!list.isEmpty())
	{
		if (list.isOneNode())
		{
			os << list.head->data;
		}
		else
		{
			auto* temp = list.head;
			while (temp != list.tail)
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