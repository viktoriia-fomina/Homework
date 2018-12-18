#include <iostream>
#include <string>
#include "Postfix.h"
#include <utility>

using namespace std;

int main()
{
	string str;
	pair<bool, int> p;
	cout << "Input string" << endl;
	cin >> str;
	cout << "result is " << fromPostfixToResult(str, p).second << endl;

	return 0;
}