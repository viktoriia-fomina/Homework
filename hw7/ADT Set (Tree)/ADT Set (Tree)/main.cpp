#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	Set tree;
	tree.add(1);
	tree.add(2);
	tree.add(0);
	tree.add(1);

	for (int i = 0; i < 20; ++i)
	{
		tree.add(i);
	}

	cout << tree.exists(2) << " " << tree.exists(1) << " " << tree.exists(0) << endl;
	// tree.remove(0);
	// tree.remove(1);
	// tree.remove(2);

	return 0;
}