#include <iostream>
#include <string>
#include "toPostfix.h"

using namespace std;

int main()
{
	string infix;
	cout << "Input expression to convert it to postfix\n";
	cin >> infix;
	string postfix;
	toPostfix(infix, postfix);
	cout << "Result is\n";
	cout << postfix << endl;

	return 0;
}