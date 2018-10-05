#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct additionalCode
{
	additionalCode(int number = 0);
	additionalCode(additionalCode const & number);
	~additionalCode();
	additionalCode & operator=(additionalCode const & number);
	void print();
	friend additionalCode operator+(additionalCode & number1, additionalCode & number2);
private:
	int* toAdditionalCode();
	int* data; // число в дополнительном коде
	int number;
};