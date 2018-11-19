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
	l.addNode("abba");
	l.addNode("ololo");
	l.addNode("tralala");
	cout << l << endl;
	cout << l.size() << endl;
	l.mergeSort();
	cout << l << endl;

	return 0;
}