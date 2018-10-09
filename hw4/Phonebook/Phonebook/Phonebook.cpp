#include "Phonebook.h"

Phonebook::Phonebook()
{
	int const size = 100;
	Subscriber* base = new Subscriber[size];
	numberOfNotes = 0;
}

Phonebook::~Phonebook()
{
	delete[] base;
	numberOfNotes = 0;
}

void Phonebook::addNote(Subscriber const & s) // 1
{
	auto temp = Subscriber(s); // is it right???
	base[numberOfNotes] = temp;
	++numberOfNotes;
}

void Phonebook::printAllNotes() const // 2
{
	for (int i = 0; i < numberOfNotes; ++i)
	{
		base[i].getName();
		printf(" ");
		base[i].getNumber();
		printf("\n");
	}
}

void Phonebook::findNumberByName(char* name) const // 3
{

}
void Phonebook::findNameByNumber(int* number, int sizeOfNumber) const // 4
{

}

void Phonebook::saveCurrentDataToFile() const // 5
{

}

// методы структуры Subscriber

Subscriber::Subscriber(char* name, char* number)
{
	int sizeOfName = strlen(name);
	this->name = new char[sizeOfName + 1];
	for (int i = 0; i < sizeOfName; ++i)
	{
		this->name[i] = name[i];
	}
	this->name[sizeOfName] = '\0';
	int sizeOfNumber = strlen(number);
	for (int i = 0; i < sizeOfNumber; ++i)
	{
		this->number[i] = number[i];
	}
	this->number[sizeOfNumber] = '\0';
}

Subscriber::Subscriber() {}

Subscriber::Subscriber(Subscriber const & s)
{
	int sizeOfName = strlen(s.name);
	this->name = new char[sizeOfName + 1];
	for (int i = 0; i < sizeOfName; ++i)
	{
		this->name[i] = s.name[i];
	}
	name[sizeOfName] = '\0';
	int  sizeOfNumber = strlen(s.number);
	this->number = new char[sizeOfNumber + 1];
	for (int i = 0; i < sizeOfNumber; ++i)
	{
		this->number[i] = s.number[i];
	}
	number[sizeOfNumber] = '\0';
}

Subscriber::~Subscriber()
{
	delete[] name;
	delete[] number;
}

void Subscriber::getName()
{
	int sizeOfName = strlen(name);
	for (int i = 0; i < sizeOfName; ++i)
	{
		printf("%c", name[i]);
	}
}

void Subscriber::getNumber()
{
	int sizeOfNumber = strlen(number);
	for (int i = 0; i < sizeOfNumber; ++i)
	{
		printf("%c", number[i]);
	}
}