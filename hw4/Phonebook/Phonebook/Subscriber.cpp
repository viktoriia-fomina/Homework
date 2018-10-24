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
		for (int i = 0; i < size; ++i)
		{
			(*destination)[i] = str[i];
		}
		(*destination)[size] = '\0';
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
	/*if (this->name != nullptr)
	{
		delete[] this->name;
	}
	int const size = (int)strlen(name);
	this->name = new char[size + 1];
	for (int i = 0; i < size; ++i)
	{
		this->name[i] = name[i];
	}
	this->name[size] = '\0';*/
	setStr(name, &(this->name));
}

char const * Subscriber::getNumber() const
{
	return number;
}

void Subscriber::setNumber(char const * number)
{
	/*if (this->number != nullptr)
	{
		delete[] this->number;
	}
	if (number != nullptr)
	{
		int const size = (int)strlen(number);
		this->number = new char[size + 1];
		for (int i = 0; i < size; ++i)
		{
			this->number[i] = number[i];
		}
		this->number[size] = '\0';
	}
	else
	{
		this->number = nullptr;
	}*/
	setStr(number, &(this->number));
}

// остальные методы

void Subscriber::print() const
{
	printf("%s  ", getName());
	printf("%s", getNumber());
	printf("\n");
}