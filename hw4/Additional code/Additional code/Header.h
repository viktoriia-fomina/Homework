#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

struct additionalCode
{
	additionalCode(int number = 0);
	additionalCode(additionalCode const & number);
	~additionalCode();
	additionalCode & operator=(additionalCode const & number);
	void print() const;
	void printInDecimalSystem() const;
	int toDecimalSystem() const;
	friend additionalCode operator+(additionalCode const & number1, additionalCode const & number2);
	int & operator[] (int const number) const;
private:
	int & operator[] (int const number);
	int toDecimalSystemPositiveNumber() const;
	int getSize() const;
	int* toAdditionalCode();
	int* data; // число в дополнительном коде
	int number;
};