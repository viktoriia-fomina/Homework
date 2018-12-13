#include "List.h"
#include "Node.h"

using namespace std;

List::List()
{
	head = nullptr;
	sizeOfList = 0;
	numOfElements = 0;
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
	numOfElements = 0;
}

void List::addElement(string const & data)
{
	if (!isEmpty())
	{
		auto* temp = head;
		if (exists(data))
		{
			while (temp->data != data)
			{
				temp = temp->next;
			}
			++temp->number;
		}
		else
		{
			temp = head;
			head = new Node(data);
			head->next = temp;
			head->previous = nullptr;
			head->next->previous = head;
			++sizeOfList;
			++head->number;
		}
	}
	else
	{
		head = new Node(data);
		++head->number;
		++sizeOfList;
	}
	++numOfElements;
}

int List::deleteElement(string const & data)
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
	--numOfElements;
	return 0;
}

void List::deleteHead(string const & data, Node* temp)
{
	if (head->next != nullptr)
	{
		if (head->number == 1)
		{
			head = head->next;
			head->previous = nullptr;
			delete temp;
			--sizeOfList;
		}
		else
		{
			--head->number;
		}
	}
	else
	{
		deleteList();
	}
}

void List::deleteElementThatIsNotHead(string const & data, Node* temp)
{
	if (temp->number == 1)
	{
		temp->previous->next = temp->next;
		if (temp->next != nullptr)
		{
			temp->next->previous = temp->previous;
		}
		delete temp;
		--sizeOfList;
	}
	else
	{
		--temp->number;
	}
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

int List::operator()(int const & index)
{
	return (*this)[index].number;
}

ostream & operator<<(ostream & os, List const & list)
{
	auto* temp = list.head;
	while (temp->next != nullptr)
	{
		os << temp->data << endl;
		temp = temp->next;
	}
	os << temp->data;
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

bool List::exists(string const & data) const
{
	bool elementExists = false;
	auto* temp = head;
	while (!elementExists && temp != nullptr)
	{
		if (head->data == data)
		{
			elementExists = true;
		}
		temp = temp->next;
	}
	return elementExists;
}

int List::numberOfElements() const
{
	return numOfElements;
}