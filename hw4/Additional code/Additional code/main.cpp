#include "Header.h"
#include <iostream>

using namespace std;

int main()
{
	auto a = additionalCode(5);
	auto b = additionalCode(-3);
	auto c = a + b;
	c.print();
	cout << endl;
	c.printInDecimalSystem();
	cout << endl;

	system("pause");
	return 0;
}