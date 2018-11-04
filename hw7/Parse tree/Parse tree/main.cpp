#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	char* str = new char[5];
	str[0] = '+';
	str[1] = '1';
	str[2] = '2';
	str[3] = '\0';
	Set s;
	s.addExpression(str);

	return 0;
}