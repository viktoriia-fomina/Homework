#pragma once
#include <string.h>

struct Subscriber
{
	explicit Subscriber(char* name, int* number, int sizeOfNumber);
	Subscriber();
	Subscriber(Subscriber const & s);
	~Subscriber();
	friend struct Phonebook;
protected:
	char* name;
	int* number;
	int sizeOfNumber;
};