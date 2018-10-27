#include <iostream>
#include <string>
#include "Postfix.h"

using namespace std;

int main()
{
	string str;
	cout << "Input string" << endl;
	cin >> str;
	cout << "result is " << fromPostfixToResult(str) << endl;


	system("pause");
	return 0;
}