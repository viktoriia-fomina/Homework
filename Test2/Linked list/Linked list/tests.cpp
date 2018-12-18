#include "tests.h"
#include <iostream>
#include "List.h"

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
	List l;
	bool canAddToIncorrectPos1 = l.addToPosition(-1, 2);
	bool canAddToIncorrectPos2 = l.addToPosition(1, 4);
	bool canBeAdded = l.addToPosition(0, 7);
	return !canAddToIncorrectPos1 && !canAddToIncorrectPos2 && canBeAdded;
}

bool test2()
{
	List l;
	bool canBeAdded1 = l.addToPosition(0, 1);
	bool canBeAdded2 = l.addToPosition(1, 2);
	bool canBeAdded3 = l.addToPosition(2, 3);
	bool canBeAdded4 = l.addToPosition(1, 5);
	return canBeAdded1 && canBeAdded2 && canBeAdded3 && canBeAdded4;
}

bool test3()
{
	List l;
	l.addToPosition(0, 4);
	l.addToPosition(1, 7);
	l.addToPosition(2, 9);
	l.addToPosition(3, 12);
	bool canBeDeleted1 = l.deleteFromThePosition(2);
	bool canBeDeleted2 = l.deleteFromThePosition(0);
	return canBeDeleted1 && canBeDeleted2;
}