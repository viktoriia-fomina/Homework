#include "Stack.h"
#include "bracket sequence.h"
#include <string>
#include <iostream>

// Написать программу проверки баланса скобок в строке, скобки могут быть трёх видов 
// : (), [], {}.Скобочная последовательность вида({ ) } считается некорректной, ({}) - корректной.

using namespace std;

int main()
{
	string s;
	cout << "Input string" << endl;
	cin >> s;
	bool result = ifBracketSequenceIsCorrect(s);
	cout << "res is " << result << endl;

	return 0;
}