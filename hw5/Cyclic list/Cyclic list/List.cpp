#include "List.h"
#include "Node.h"

// конструктор - деструктор

List::List()
{
	head = nullptr;
}

List::~List()
{
	if (!isEmpty())
	{ 
		while (!ifOneNode())
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
		head->next = nullptr;
		delete head;
		head = nullptr;
	}
}

// задача Иосифа

int List::josephusProblem(int const numberOfWarriors, int const murderFrequency)
{
	for (int i = numberOfWarriors; i >= 1; --i)
	{
		addNode(i);
	}
	auto* temp = head;
	auto* nextAfterElementToDelete = temp;
	while (!ifOneNode())
	{
		temp = nextAfterElementToDelete;
		for (int i = 0; i < murderFrequency - 1; ++i)
		{
			temp = temp->next;
		}
		int numberOfCurrentWarrior = temp->data;
		nextAfterElementToDelete = temp->next;
		deleteNode(numberOfCurrentWarrior);
	}
	return head->data;
}

// добавление элемента

void List::addNode(int const data)
{
	auto* newElement = new Node(data);
	if (!isEmpty())
	{
		if (!ifOneNode())
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
		this->~List();
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