#include "tests.h"
#include "Set.h"
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
	bool ifElementIsInTheSet = s.exists(2);
	bool isEmpty = s.isEmpty();
	bool ifWasDeleted = s.remove(3);
	bool ifWasAdded = s.add(7);
	return !ifElementIsInTheSet && isEmpty && !ifWasDeleted && ifWasAdded;
}

bool test2()
{
	Set s;
	s.add(1);
	s.add(-5);
	s.add(0);
	bool ifAddedAgain = s.add(1);
	bool ifExist = (s.exists(1) && s.exists(-5) && s.exists(0));
	s.remove(1);
	bool ifWasDeleted = s.exists(1);
	return !ifAddedAgain && ifExist && !ifWasDeleted;
}

bool test3()
{
	Set s;
	s.add(3);
	s.remove(3);
	bool isEmpty = s.isEmpty();
	bool ifRemovedAgain = s.remove(3);
	return isEmpty && !ifRemovedAgain;
}