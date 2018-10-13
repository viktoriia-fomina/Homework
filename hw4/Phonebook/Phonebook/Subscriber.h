#pragma once
#include <stdio.h>
#include <string.h>

struct Subscriber
{
	// конструктор - оператор копирования - деструктор
	explicit Subscriber(char const * name, char const * number);
	Subscriber();
	Subscriber(Subscriber const & s);
	Subscriber & operator=(Subscriber const & s);
	~Subscriber();

	// getter - setter
	char const * getName() const;
	void setName(char const * name);
	char const * getNumber() const;
	void setNumber(char const * number);

	// остальные методы
	void print();
private:
	char* name;
	char* number;
};