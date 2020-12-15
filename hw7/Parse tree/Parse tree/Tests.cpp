#include "Tests.h"
#include "ParseTree.h"
#include "Node.h"
#include <iostream>

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
	ParseTree s;
	char test[] = "+11";
	s.addExpression(test);
	return s.getResult() == 2;
}

bool test2()
{
	ParseTree s;
	char test[] = "/9(-52)";
	s.addExpression(test);
	return s.getResult() == 3;
}

bool test3()
{
	ParseTree s;
	char test[] = "+1(*(+52)(-73))";
	s.addExpression(test);
	return s.getResult() == 29;
}