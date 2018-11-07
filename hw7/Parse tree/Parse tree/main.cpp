#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	char* str = new char[8];
	str[0] = '*';
	str[1] = '(';
	str[2] = '+';
	str[3] = '1';
	str[4] = '2';
	str[5] = ')';
	str[6] = '3';
	str[7] = '\0';
	Set s;
	s.addExpression(str);

	return 0;
}