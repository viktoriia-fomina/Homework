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

int List::josephusProblem(int const numberOfWarriors, int const numberToBeSkipped)
{
	for (int i = numberOfWarriors; i >= 1; --i)
	{
		addNode(i);
	}
	auto* temp = head;
	while (!ifOneNode())
	{
		for (int i = 0; i < numberToBeSkipped; ++i)
		{
			temp = temp->next;
		}
		int numberOfCurrentWarrior = temp->data;
		deleteNode(numberOfCurrentWarrior);
	}
	return head->data;
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
		cout << "List is empty. Node can not be deleted\n";
	}
	else
	{
		if (head->next == head)
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

bool List::isEmpty() const
{
	return head == nullptr;
}

bool List::ifOneNode() const
{
	return head == head->next;
}

int List::getHead() const
{
	return head->data;
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