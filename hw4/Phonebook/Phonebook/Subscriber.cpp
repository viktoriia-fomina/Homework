#include "Subscriber.h"

// конструктор - оператор копирования - деструктор

Subscriber::Subscriber(char const * name, char const * number)
{
	this->name = nullptr;
	this->number = nullptr;
	setName(name);
	setNumber(number);
}

Subscriber::Subscriber() 
{
	this->name = nullptr;
	this->number = nullptr;
}

Subscriber::Subscriber(Subscriber const & s)
{
	this->name = nullptr;
	this->number = nullptr;
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

char const * Subscriber::getName() const
{
	return name;
}

void Subscriber::setName(char const * name)
{
	if (this->name != nullptr)
	{
		delete[] this->name;
	}
	int const size = (int)strlen(name);
	this->name = new char[size + 1];
	for (int i = 0; i < size; ++i)
	{
		this->name[i] = name[i];
	}
	this->name[size] = '\0';
}

char const * Subscriber::getNumber() const
{
	return number;
}

void Subscriber::setNumber(char const * number)
{
	if (this->number != nullptr)
	{
		delete[] this->number;
	}
	int const size = (int)strlen(number);
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
	printf("\n");
}