#include "tests.h"
#include <iostream>
#include "bracket sequence.h"

using namespace std;

bool test1();

bool test2();

bool test3();

void tests()
{
	if (test1())
	{
		cout << "Test 1 passed" << endl;
	}
	else
	{
		cout << "Test 1 FAILED" << endl;
	}
	if (test2())
	{
		cout << "Test 2 passed" << endl;
	}
	else
	{
		cout << "Test 2 FAILED" << endl;
	}
	if (test3())
	{
		cout << "Test 3 passed" << endl;
	}
	else
	{
		cout << "Test 3 FAILED" << endl;
	}
}

bool test1()
{
	return !ifBracketSequenceIsCorrect("([])[(])");
}

bool test2()
{
	return ifBracketSequenceIsCorrect("()()()[][({})]");
}

bool test3()
{
	return !ifBracketSequenceIsCorrect(")()()");
}