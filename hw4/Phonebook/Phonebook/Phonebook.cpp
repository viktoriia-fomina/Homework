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
	base[numberOfNotes] = s;
	++numberOfNotes;
}

void Phonebook::printAllNotes() const // 2
{
	
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