#include "Tests.h"
#include "Set.h"
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
	Set s;
	char test[] = "+11";
	s.addExpression(test);
	return s.getHead()->data == '+' && s.getHead()->leftChild->data == '1' && s.getHead()->rightChild->data == '1'
			&& s.getResult() == 2;
}

bool test2()
{
	Set s;
	char test[] = "/9(-52)";
	s.addExpression(test);
	return s.getHead()->data == '/' && s.getHead()->leftChild->data == '9' && s.getHead()->rightChild->data == '-'
			&& s.getHead()->rightChild->leftChild->data == '5' && s.getHead()->rightChild->rightChild->data == '2'
			&& s.getResult() == 3;
}

bool test3()
{
	Set s;
	char test[] = "+1(*(+52)(-73))";
	s.addExpression(test);
	return s.getHead()->data == '+' && s.getHead()->leftChild->data == '1' && s.getHead()->rightChild->data == '*'
			&& s.getHead()->rightChild->leftChild->data == '+' && s.getHead()->rightChild->rightChild->data == '-'
			&& s.getHead()->rightChild->leftChild->leftChild->data == '5' &&
			s.getHead()->rightChild->leftChild->rightChild->data == '2' &&
			s.getHead()->rightChild->rightChild->leftChild->data == '7' &&
			s.getHead()->rightChild->rightChild->rightChild->data == '3' && s.getResult() == 29;
}