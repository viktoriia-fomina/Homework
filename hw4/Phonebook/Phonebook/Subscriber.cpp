#include "Subscriber.h"
#include <stdio.h>
#include <string.h>

// конструктор - оператор копирования - деструктор

Subscriber::Subscriber(char const * name, char const * number)
{
	setName(name);
	setNumber(number);
}

Subscriber::Subscriber() {}

Subscriber::Subscriber(Subscriber const & s)
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

char const * Subscriber::getName()
{
	return name;
}

void Subscriber::setName(char const * name)
{
	if (name != nullptr)
	{
		delete[] this->name;
	}
	int const size = strlen(name);
	this->name = new char[size + 1];
	for (int i = 0; i < size; ++i)
	{
		this->name[i] = name[i];
	}
	this->name[size] = '\0';
}

char const * Subscriber::getNumber()
{
	return number;
}

void Subscriber::setNumber(char const * number)
{
	if (number != nullptr)
	{
		delete[] this->number;
	}
	int const size = strlen(number);
	this->number = new char[size + 1];
	for (int i = 0; i < size; ++i)
	{
		this->number[i] = number[i];
	}
	this->number[size] = '\0';
}

// остальные методы

void Subscriber::print()
{
	printf("%s  ", getName());
	printf("%s", getNumber());
}