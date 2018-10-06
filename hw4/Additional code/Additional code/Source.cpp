// ������ ��� �����, ��������� � �������� ������������� � �������������� ���� � ����������, 
// ������� � ������� � �������� �������������, ������� �����, ��������� � ����������, 
// ������� ����� � ���������� ����.��� ��������� ������ �� - ������(������������� ������������ 
// ������� setlocale, ����� ��������� ���������� �� - ������ � ��� Windows ����).

#include "Header.h"

additionalCode::additionalCode(int number)
{
	this->number = number;
	this->data = toAdditionalCode();
}

additionalCode::additionalCode(additionalCode const & number)
{
	this->number = number.number;
	this->data = toAdditionalCode(); // ???
}

additionalCode::~additionalCode()
{
	number = 0;
	delete[] data;
}

additionalCode & additionalCode::operator=(additionalCode const & number)
{
	delete[] this->data;
	this->number = number.number;
	this->data = toAdditionalCode(); // ???
	return *this;
}

void additionalCode::print() const
{
	bool ifFirstIsZero = false;
	if (data[0] == 0)
	{
		ifFirstIsZero = true;
	}
	for (int i = 0; i < getSize(); ++i)
	{
		while (ifFirstIsZero)
		{
			i++;
			if (data[i] != 0)
			{
				ifFirstIsZero = false;
				break;
			}
		}
		printf("%i", data[i]);
	}
}

void additionalCode::printInDecimalSystem() const
{
	printf("%i", this->number);
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
				sum.data[size - i - 1] = 1;
			}
			else
			{
				sum.data[size - i - 1] = 0;
				temp = 1;
			}
		}
		else if ((number1.data[size - i - 1] == 1 || number2.data[size - i - 1] == 1) && temp == 1)
		{
			sum.data[size - i - 1] = 0;
		}
		else
		{
			if (temp == 1)
			{
				sum.data[size - i - 1] = 1;
				temp = 0;
			}
			else
			{
				sum.data[size - i - 1] = number1.data[size - i - 1] + number2.data[size - i - 1];
			}
		}
	}
	sum.number = number1.number + number2.number;
	return sum;
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
	// ������� ����� � �������� ������� � ������
	for (int i = 0; i < size; ++i)
	{
		numberToAdditionalCode[size - i - 1] = num & 1;
		num >>= 1;
	}
	// ���� ����� �������������, �� ��������� ��� � �������� ���, � ����� � ��������������
	if (number < 0)
	{
		// ������� � �������� ���
		for (int i = 0; i < size; ++i)
		{
			numberToAdditionalCode[i] == 0 ? numberToAdditionalCode[i] = 1 : numberToAdditionalCode[i] = 0;
		}
		// ������� � �������������� ���
		int temp = 1;
		for (int i = 0; i < size; ++i)
		{
			while (temp == 1)
			{
				if (numberToAdditionalCode[size - i - 1] == 1)
				{
					numberToAdditionalCode[size - i - 1] = 0;
				}
				else
				{
					numberToAdditionalCode[size - i - 1] = 1;
					temp = 0;
				}
			}
		}
	}
	return numberToAdditionalCode;
}