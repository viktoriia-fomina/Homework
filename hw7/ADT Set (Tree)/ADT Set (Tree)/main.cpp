#include <iostream>
#include "Set.h"
#include "List.h"

using namespace std;

int main()
{
	Set tree;
	tree.add(1);
	tree.add(2);
	tree.add(0);
	tree.add(1);
	tree.add(3);
	tree.add(-2);

	cout << tree.exists(2) << " " << tree.exists(1) << " " << tree.exists(0) << endl;
	// tree.remove(0);
	// tree.remove(1);
	// tree.remove(2);
	cout << "Testing:\n";
	tree.printInDescendingOrder();

	return 0;
}