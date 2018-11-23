#include <iostream>
#include <string>
#include "Postfix.h"
#include <utility>

using namespace std;

int main()
{
	string str;
	pair <bool, int> p;
	cout << "Input string" << endl;
	cin >> str;
	if (!fromPostfixToResult(str, p).first)
	{
		cout << "Incorrect expression" << endl;
	}
	else
	{
		cout << "result is " << fromPostfixToResult(str, p).second << endl;
	}

	return 0;
}