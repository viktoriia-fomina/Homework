#include "List.h"
#include "Node.h"

using namespace std;

List::List()
{
	head = nullptr;
	sizeOfList = 0;
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
	sizeOfList = 0;
}

void List::addNode(string const & data)
{
	if (!isEmpty())
	{
		auto* temp = head;
		head = new Node(data);
		head->next = temp;
		head->previous = nullptr;
		head->next->previous = head;
	}
	else
	{
		head = new Node(data);
	}
	++sizeOfList;
}

int List::deleteNode(string const & data)
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

void List::deleteHead(string const & data, Node* temp)
{
	if (head->next != nullptr)
	{
		head = head->next;
		head->previous = nullptr;
		delete temp;
		--sizeOfList;
	}
	else
	{
		deleteList();
	}
}

void List::deleteElementThatIsNotHead(string const & data, Node* temp)
{
	if (temp->next != nullptr)
	{
		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
	}
	else
	{
		temp->previous->next = nullptr;
	}
	delete temp;
	--sizeOfList;
}

Node & List::operator[](int const & index)
{
	int i = 0;
	auto* temp = head;
	while (i < index && temp->next != nullptr)
	{
		temp = temp->next;
		++i;
	}
	return *temp;
}

ostream & operator<<(ostream & os, List const & list)
{
	auto* temp = list.head;
	while (temp != nullptr)
	{
		os << temp->data << endl;
		temp = temp->next;
	}
	return os;
}

bool List::isEmpty() const
{
	return head == nullptr;
}

int List::size() const
{
	return sizeOfList;
}