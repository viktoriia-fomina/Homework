#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	Set s;
	s.add(0);
	s.add(1);
	s.add(-5);
	s.add(0);
	s.add(9);
	cout << "des" << endl;
	s.printInDescendingOrder();
	cout << endl;
	cout << "asc" << endl;
	s.printInAscendingOrder();

	return 0;
}