#include <iostream>
#include "Set.h"
#include <fstream>

using namespace std;

int readInfoFromFile();

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
	readInfoFromFile();

	return 0;
}

int readInfoFromFile()
{
	Set s;
	fstream file("data.txt", ios::in);
	if (!file.is_open())
	{
		cout << "File not found" << endl;
		return -1;
	}
	int const size = 100;
	char* buffer = new char[size] {};
	while (!file.eof())
	{
		file.getline(buffer, size);
		s.addExpression(buffer);
		s.printExpression();
		cout << endl;
		s.getResultOfExpression();
		cout << endl;
	}
	file.close();
	delete[] buffer;
	return 0;
}

//+(-(+12)3)4
//+(*23)6
//+2(*36)
//*(+11)2
//*2(+36)
//*(+23)(+45)
//*(*(+23)(+45))(+7(+89))