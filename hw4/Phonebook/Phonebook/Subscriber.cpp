#define _CRT_SECURE_NO_WARNINGS
#include "Subscriber.h"
#include <stdio.h>
#include <string.h>

// конструктор - оператор копирования - деструктор

Subscriber::Subscriber(char const * name, char const * number) : Subscriber()
{
	setName(name);
	setNumber(number);
}

Subscriber::Subscriber() 
{
	this->name = nullptr;
	this->number = nullptr;
}

Subscriber::Subscriber(Subscriber const & s) : Subscriber()
{
	setName(s.name);
	setNumber(s.number);
}

Subscriber & Subscriber::operator=(Subscriber const & s)
{
	if (this != &s)
	{
		setName(s.name);
		setNumber(s.number);
	}
	return *this;
}

Subscriber::~Subscriber()
{
	delete[] name;
	delete[] number;
}

// getter - setter

void Subscriber::setStr(char const * str, char** destination)
{
	if (*destination != nullptr)
	{
		delete[] *destination;
	}
	if (str != nullptr)
	{
		int const size = (int)strlen(str);
		*destination = new char[size + 1];
		strcpy(*destination, str);
	}
	else
	{
		*destination = nullptr;
	}
}

char const * Subscriber::getName() const
{
	return name;
}

void Subscriber::setName(char const * name)
{
	setStr(name, &(this->name));
}

char const * Subscriber::getNumber() const
{
	return number;
}

void Subscriber::setNumber(char const * number)
{
	setStr(number, &(this->number));
}

// остальные методы

void Subscriber::print() const
{
	printf("%s  ", getName());
	printf("%s", getNumber());
	printf("\n");
}