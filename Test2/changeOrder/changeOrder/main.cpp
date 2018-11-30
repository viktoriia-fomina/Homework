#include <iostream>
#include "readFromFile.h"
#include "List.h"

using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	cout << "Input first number" << endl;
	cin >> a;
	cout << "Input second number (must be greater than first number)" << endl;
	cin >> b;
	if (a > b)
	{
		cout << "First number is greater than second!!!" << endl;
		return -1;
	}
	
	List l1;
	List l2;
	List l3;
	writeToLists(a, b, l1, l2, l3);
	writeFromListsToFile(l1, l2, l3);

	return 0;
}