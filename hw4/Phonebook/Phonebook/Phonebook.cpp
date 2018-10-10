#include "Phonebook.h"
#include "Subscriber.h"

// конструкторы - оператор присваивания - деструктор

Phonebook::Phonebook()
{
	int const size = 100;
	Subscriber* base = new Subscriber[size];
	numberOfNotes = 0;
}

Phonebook::Phonebook(Phonebook const & p)
{
	int const size = 100;
	Subscriber* base = new Subscriber[size];
	numberOfNotes = p.numberOfNotes;
	for (int i = 0; i < numberOfNotes; ++i)
	{
		base[i] = p.base[i];
	}
}

Phonebook & Phonebook::operator=(Phonebook const & p)
{
	return *this;
}

Phonebook::~Phonebook()
{
	delete[] base;
	numberOfNotes = 0;
}

void Phonebook::addNote(Subscriber const & s) // 1
{
	auto temp = s;
	base[numberOfNotes] = temp;
	++numberOfNotes;
}

void Phonebook::printAllNotes() const // 2
{
	
}

void Phonebook::findNumberByName(char const * name) const // 3
{

}
void Phonebook::findNameByNumber(int const * number, int sizeOfNumber) const // 4
{

}

void Phonebook::saveToFile() const // 5
{

}