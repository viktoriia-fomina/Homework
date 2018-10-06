#include "Header.h"

additionalCode::additionalCode(int number)
{
	this->number = number;
	this->data = toAdditionalCode();
}

additionalCode::additionalCode(additionalCode const & number)
{
	this->number = number.number;
	this->data = toAdditionalCode();
}

additionalCode::~additionalCode()
{
	number = 0;
	delete[] data;
}

additionalCode & additionalCode::operator=(additionalCode const & number)
{
	if (this != &number)
	{
		delete[] this->data;
		this->number = number.number;
		this->data = toAdditionalCode();
	}
	return *this;
}

void additionalCode::print() const
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
			i++;
			if ((*this)[i] != 0)
			{
				ifFirstIsZero = false;
				break;
			}
			if (i == size - 1)
			{
				for (int j = 0; j < size; ++j)
				{
					(*this)[j] = 0;
				}
				break;
			}
		}
		printf("%i", (*this)[i]);
	}
}

void additionalCode::printInDecimalSystem() const
{
	printf("%i", this->toDecimalSystem());
}

additionalCode operator+(additionalCode & number1, additionalCode & number2)
{
	auto sum = additionalCode();
	int temp = 0;
	int const size = number1.getSize();
	for (int i = 0; i < size; ++i)
	{
		if (number1.data[size - i - 1] == 1 && number2.data[size - i - 1] == 1)
		{
			if (temp == 1)
			{
				sum[size - i - 1] = 1;
			}
			else
			{
				sum[size - i - 1] = 0;
				temp = 1;
			}
		}
		else if ((number1[size - i - 1] == 1 || number2[size - i - 1] == 1) && temp == 1)
		{
			sum.data[size - i - 1] = 0;
		}
		else
		{
			if (temp == 1)
			{
				sum[size - i - 1] = 1;
				temp = 0;
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

int & additionalCode::operator[] (int const number)
{
	return data[number];
}

int & additionalCode::operator[] (int const number) const
{
	return data[number];
}

int additionalCode::toDecimalSystem() const
{
	int ifNumberIsNegative = false;
	for (int i = 0; i < 16; ++i)
	{
		if ((*this)[i] == 1)
		{
			ifNumberIsNegative = true;
			break;
		}
	}
	int const size = getSize();
	int number = 0;
	if (ifNumberIsNegative)
	{
		// из числа -4 получим 4, то есть из дополнительного кода элемента получим код
		// элемента обратного ему по сложению (эту операцию применяем только к отрицательным числам)
		auto temp = additionalCode(number - 1);
		for (int i = 0; i < size; ++i)
		{
			temp[i] == 0 ? temp[i] = 1 : temp[i] = 0;
		}
		number = toDecimalSystemPositiveNumber();
		number *= 1;
	}
	else
	{
		number = toDecimalSystemPositiveNumber();
	}
	return number;
}

int additionalCode::toDecimalSystemPositiveNumber() const
{
	int const size = getSize();
	int number = 0;
	for (int i = 0; i < size; ++i)
	{
		number += (int)((*this)[size - i - 1] * pow(2, i));
	}
	return number;
}

int additionalCode::getSize() const
{
	return 32;
}

int* additionalCode::toAdditionalCode()
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