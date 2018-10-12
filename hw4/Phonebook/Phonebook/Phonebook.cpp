#include "Phonebook.h"
#include "Subscriber.h"
#include <stdio.h>
#include <string.h>

// конструкторы - оператор присваивания - деструктор

Phonebook::Phonebook()
{
	int const size = 100;
	base = new Subscriber[size];
	numberOfNotes = 0;
}

Phonebook::Phonebook(Phonebook const & p) {}

Phonebook & Phonebook::operator=(Phonebook const & p) 
{
	return *this;
}

Phonebook::~Phonebook()
{
	delete[] base;
	numberOfNotes = 0;
}

// getter - setter

Subscriber Phonebook::operator[](int number) const
{
	return base[number];
}

Subscriber & Phonebook::operator[](int number)
{
	return base[number];
}

int Phonebook::size() const
{
	return numberOfNotes;
}

// остальные методы

void Phonebook::addNote(Subscriber const & note) // 1
{
	(*this)[numberOfNotes] = note;
	++numberOfNotes;
}

void Phonebook::printAllNotes() const // 2
{
	int const size = this->size();
	for (int i = 0; i < size; ++i)
	{
		(*this)[i].print();
	}
}

bool compareStr(char const * name1, char const * name2)
{
	if (strlen(name1) != strlen(name2))
	{
		return false;
	}
	int const length = strlen(name1);
	for (int i = 0; i < length; ++i)
	{
		if (name1[i] != name2[i])
		{
			return false;
		}
	}
	return true;
}

void Phonebook::findNumberByName(char const * name) const // 3
{
	for (int i = 0; i < size(); ++i)
	{
		if (compareStr((*this)[i].getName(), name))
		{
			(*this)[i].print();
		}
	}
}

void Phonebook::findNameByNumber(char const * number) const // 4
{
	for (int i = 0; i < size(); ++i)
	{
		if (compareStr((*this)[i].getNumber(), number))
		{
			(*this)[i].print();
		}
	}
}

void Phonebook::saveToFile() const // 5
{

}