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
	cout << tree.exists(2) << " " << tree.exists(1) << " " << tree.exists(0) << endl;

	return 0;
}