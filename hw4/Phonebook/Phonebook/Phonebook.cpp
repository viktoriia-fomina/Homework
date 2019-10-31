#define _CRT_SECURE_NO_WARNINGS
#include "Phonebook.h"
#include "Subscriber.h"
#include <stdio.h>
#include <string.h>

// конструкторы - деструктор

Phonebook::Phonebook()
{
	base = new Subscriber[100];
	numberOfNotes = 0;
	readInfoFromFile();
}

int Phonebook::readInfoFromFile()
{
	FILE* file = fopen("phonebook.txt", "r");
	int const sizeData = 100;
	int const sizeBuffer = 20;
	if (!file)
	{
		printf("File could not be opened\n");
		return -1;
	}
	char* data[sizeData] = {};
	int linesRead = 0;
	while (!feof(file))
	{
		char* buffer = new char[sizeBuffer];
		int const readBytes = fscanf(file, "%s", buffer);
		if (readBytes < 0)
		{
			delete[] buffer;
			break;
		}
		data[linesRead] = buffer;
		++linesRead;
	}
	if (linesRead > 0)
	{
		numberOfNotes = linesRead / 2;
		for (int i = 0; i < linesRead; ++i)
		{
			Subscriber s(data[i], data[i + 1]);
			(*this)[i / 2] = s;
			++i;
		}
		for (int i = 0; i < linesRead; ++i)
		{
			delete[] data[i];
		}
	}
	fclose(file);
	return 0;
}

Phonebook::~Phonebook()
{
	delete[] base;
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

void Phonebook::findNumberByName(char const * name) const // 3
{
	for (int i = 0; i < size(); ++i)
	{
		if (strcmp((*this)[i].getName(), name))
		{
			(*this)[i].print();
		}
	}
}

void Phonebook::findNameByNumber(char const * number) const // 4
{
	for (int i = 0; i < size(); ++i)
	{
		if (strcmp((*this)[i].getNumber(), number))
		{
			(*this)[i].print();
		}
	}	
}

int Phonebook::saveToFile() const // 5
{
	FILE* file = fopen("phonebook.txt", "w");
	if (!file)
	{
		printf("FILE WAS NOT FOUND\n!");
		return -1;
	}	
	for (int i = 0; i < numberOfNotes; ++i)
	{
		fwrite((*this)[i].getName(), sizeof(char), strlen((*this)[i].getName()), file);
		fwrite(" ", sizeof(char), 1, file);
		fwrite((*this)[i].getNumber(), sizeof(char), strlen((*this)[i].getNumber()), file);
		fwrite("\n", sizeof(char), 1, file);
	}
	fclose(file);
	return 0;
}