#include "Tests.h"
#include "List.h"
#include <iostream>
#include "ForStrings.h"

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
	l.addNode("alala", "123");
	l.addNode("cucu", "678");
	l.addNode("blabla", "34");
	l.mergeSort(1);
	return l[0].firstWord == "alala" && l[1].firstWord == "blabla" && l[2].firstWord == "cucu";
}

bool test2()
{
	List l;
	l.addNode("tutu", "123");
	l.addNode("abba", "123");
	l.addNode("baba", "123");
	return l[0].secondWord == "123" && l[1].secondWord == "123" && l[2].secondWord == "123";
}

bool test3()
{
	List l;
	l.addNode("cococo", "8800");
	l.addNode("mu", "880");
	l.addNode("meow", "7690");
	l.addNode("igogo", "4878");
	l.addNode("ia", "4848839");
	l.addNode("cucumber", "30054");
	return l[0].secondWord == "30054" && l[1].secondWord == "4848839" && l[2].secondWord == "4878" && 
			l[3].secondWord == "7690" && l[4].secondWord == "880" && l[5].secondWord == "8800";
}