#include "Tests.h"
#include "List.h"
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
	List l;
	l.addNode("alala");
	l.addNode("cucu");
	l.addNode("blabla");
	l.mergeSort();
	return l[0].data == "alala" && l[1].data == "blabla" && l[2].data == "cucu";
}

bool test2()
{
	List l;
	l.addNode("ololo");
	l.addNode("ololo");
	l.addNode("ololo");
	return l[0].data == "ololo" && l[1].data == "ololo" && l[2].data == "ololo";
}

bool test3()
{
	List l;
	l.addNode("8800");
	l.addNode("880");
	l.addNode("7690");
	l.addNode("4878");
	l.addNode("4848839");
	l.addNode("30054");
	return l[0].data == "30054" && l[1].data == "4848839" && l[2].data == "4878" && l[3].data == "7690" &&
			l[4].data == "880" && l[5].data == "8800";
}