#include "AdditionalCode.h"
#include <cassert>

AdditionalCode::AdditionalCode(int number)
{
	this->number = number;
	this->data = toAdditionalCode();
}

AdditionalCode::AdditionalCode(AdditionalCode const & number)
{
	this->number = number.number;
	this->data = toAdditionalCode();
}

AdditionalCode::~AdditionalCode()
{
	delete[] data;
}

AdditionalCode & AdditionalCode::operator=(AdditionalCode const & number)
{
	if (this != &number)
	{
		delete[] this->data;
		this->number = number.number;
		this->data = toAdditionalCode();
	}
	return *this;
}

void AdditionalCode::print() const
{
	int const size = getSize();
	bool ifFirstIsZero = false;
	if ((*this)[0] == 0)
	{
		ifFirstIsZero = true;
	}
	for (int i = 0; i < size; ++i)
	{
		while (ifFirstIsZero)
		{
			++i;
			if ((*this)[i] != 0)
			{
				ifFirstIsZero = false;
				break;
			}
		}
		printf("%i", (*this)[i]);
	}
}

void AdditionalCode::printInDecimalSystem() const
{
	printf("%i", this->toDecimalSystem());
}

AdditionalCode operator+(AdditionalCode const & number1, AdditionalCode const & number2)
{
	auto sum = AdditionalCode();
	bool temp = false;
	assert(number1.getSize() == number2.getSize() && "Different sizes of numbers\n");
	int const size = number1.getSize();
	for (int i = 0; i < size; ++i)
	{
		if (number1[size - i - 1] == 1 && number2[size - i - 1] == 1)
		{
			if (temp == true)
			{
				sum[size - i - 1] = 1;
			}
			else
			{
				sum[size - i - 1] = 0;
				temp = true;
			}
		}
		else if ((number1[size - i - 1] == 1 || number2[size - i - 1] == 1) && temp)
		{
			sum[size - i - 1] = 0;
		}
		else
		{
			if (temp == true)
			{
				sum[size - i - 1] = 1;
				temp = false;
			}
			else
			{
				sum[size - i - 1] = number1[size - i - 1] + number2[size - i - 1];
			}
		}
	}
	sum.number = number1.number + number2.number;
	return sum;
}

int & AdditionalCode::operator[] (int const number) const
{
	return data[number];
}

int & AdditionalCode::operator[] (int const number)
{
	return data[number];
}

int AdditionalCode::toDecimalSystem() const
{
	int const size = getSize();
	int number = 0;
	int powerOfTwo = 1;
	for (int i = 0; i < size; ++i)
	{
		number += (int)((*this)[size - i - 1] * powerOfTwo);
		powerOfTwo *= 2;
	}
	return number;
}

int AdditionalCode::getSize() const
{
	return 32;
}

int* AdditionalCode::toAdditionalCode()
{
	int const size = getSize();
	int num = number;
	int* numberToAdditionalCode = new int[size];
	for (int i = 0; i < size; ++i)
	{
		numberToAdditionalCode[size - i - 1] = num & 1;
		num >>= 1;
	}
	return numberToAdditionalCode;
}