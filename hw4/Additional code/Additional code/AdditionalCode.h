#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

struct AdditionalCode
{
	explicit AdditionalCode(int number = 0);
	AdditionalCode(AdditionalCode const & number);
	~AdditionalCode();
	AdditionalCode & operator=(AdditionalCode const & number);
	void print() const;
	void printInDecimalSystem() const;
	int toDecimalSystem() const;
	friend AdditionalCode operator+(AdditionalCode const & number1, AdditionalCode const & number2);
	int & operator[] (int const number) const;
private:
	int & operator[] (int const number);
	int getSize() const;
	int* toAdditionalCode();
	int* data; // число в дополнительном коде
	int number;
};