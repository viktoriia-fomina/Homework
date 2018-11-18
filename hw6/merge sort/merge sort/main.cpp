#include <iostream>
#include "List.h"
#include <string>
#include <fstream>
#include "Node.h"

using namespace std;

int main()
{
	List l;
	l.addNode("aaa");
	l.addNode("lala");
	l.addNode("caca");
	//l.addNode("abba");
	//l.addNode("ololo");
	//l.addNode("tralala");
	cout << l << endl;
	cout << l.size() << endl;
	//l.mergeSort();
	cout << l << endl;
	Node n1("lala");
	Node n2("caca");
	if (n1 < n2)
	{
		cout << "not true" << endl;
	}
	if (n2 > n1)
	{
		cout << "true" << endl;
	}
	return 0;
}