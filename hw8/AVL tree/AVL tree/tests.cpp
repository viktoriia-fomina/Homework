#include "test.h"
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
	s.addValueByKey("tralala", "1");
	s.addValueByKey("ololo", "2");
	s.addValueByKey("ololo", "3");
	return s.getValueByKey("tralala") == "1" && s.keyExists("ololo") && s.getValueByKey("ololo") == "3";
}

bool test2()
{
	Set s;
	s.addValueByKey("tralala", "1");
	s.addValueByKey("ololo", "2");
	s.addValueByKey("lol", "3");
	s.addValueByKey("lala", "4");
	s.addValueByKey("alala", "5");
	s.deleteNodeByKey("lala");
	return !s.keyExists("lala") && s.keyExists("ololo") && !s.isEmpty() && s.getValueByKey("alala") == "5";
}

bool test3()
{
	Set s;
	s.addValueByKey("lol", "1");
	s.deleteNodeByKey("lol");
	return !s.keyExists("lol") && s.isEmpty();
}