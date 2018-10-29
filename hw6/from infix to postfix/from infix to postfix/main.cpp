#include <iostream>
#include <string>
#include "Infix to postfix.h"

using namespace std;

int main()
{
	string infix;
	cout << "Input infix expression\n";
	cin >> infix;
	string postfix = "                 ";
 	infixToPostfix(infix, postfix);
	cout << postfix << endl;

	system("pause");
	return 0;
}