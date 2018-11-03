#include <iostream>
#include "Set.h"
#include "List.h"
#include <ctime>

using namespace std;

int main()
{
	srand(time(nullptr));
	Set tree;
	tree.add(1);
	tree.add(2);
	tree.add(0);

	for (int i = 0; i < 10; ++i)
	{
		tree.add(rand() % 10 - 20);
	}
	cout << "Testing:\n";
	tree.printInDescendingOrder();
	cout << endl;
	tree.printInAscendingOrder();
	cout << endl;

	return 0;
}