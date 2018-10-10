#include "Subscriber.h"

Subscriber::Subscriber(char* name, int* number, int sizeOfNumber)
{
	int nameSize = strlen(name);
	this->name = new char[nameSize + 1];
	for (int i = 0; i < nameSize; ++i)
	{
		this->name[i] = name[i];
	}
	this->name[nameSize] = '\0';
	this->number = new int[sizeOfNumber];
	for (int i = 0; i < sizeOfNumber; ++i)
	{
		this->number[i] = number[i];
	}
	this->sizeOfNumber = sizeOfNumber;
}

Subscriber::Subscriber(){}

Subscriber::Subscriber(Subscriber const & s)
{
	int nameSize = strlen(s.name);
	this->name = new char[nameSize + 1];
	for (int i = 0; i < nameSize; ++i)
	{
		this->name[i] = s.name[i];
	}
	this->name[nameSize] = '\0';
	this->sizeOfNumber = s.sizeOfNumber;
	int* number = new int[sizeOfNumber];
	for (int i = 0; i < sizeOfNumber; ++i)
	{
		this->number[i] = s.number[i];
	}
}

Subscriber::~Subscriber()
{
	delete[] name;
	delete[] number;
	sizeOfNumber = 0;
}