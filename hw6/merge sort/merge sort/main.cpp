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
	l.addNode("trolo");
	l.addNode("epic");
	/*l.addNode("1323");
	l.addNode("90073");
	l.addNode("132");
	l.addNode("8203");*/
	cout << l << endl;
	cout << l.size() << endl;
	l.mergeSort();
	cout << l << endl;



	return 0;
}