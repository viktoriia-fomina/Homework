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
			++head->number;
			++sizeOfList;
		}
	}
	else
	{
		head = new Node(data);
		++head->number;
		++sizeOfList;
	}
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

Node & List::operator[](int const & index) const
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

void List::printData(int const & index) const
{
	cout << (*this)[index].data << " " << (*this)[index].number;
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

bool List::exists(string const & data) const
{
	bool elementExists = false;
	auto* temp = head;
	while (!elementExists && temp != nullptr)
	{
		if (temp->data == data)
		{
			elementExists = true;
		}
		temp = temp->next;
	}
	return elementExists;
}