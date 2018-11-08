#include "Read from file.h"
#include "Set.h"
#include <iostream>
#include <fstream>

using namespace std;

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
		cout << "Expression: ";
		s.printExpression();
		cout << endl;
		cout << "Result is " << s.getResult();
		cout << endl;
		s.deleteExpression();
	}
	file.close();
	delete[] buffer;
	return 0;
}