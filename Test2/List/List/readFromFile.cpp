#include "readFromFile.h"
#include "List.h"
#include <fstream>

using namespace std;

bool writeToList(List & l)
{
	ifstream file;
	file.open("numbers.txt", ios::in);
	if (!file.is_open())
	{
		cout << "File not found" << endl;
		return false;
	}
	int number = 0;
	while (!file.eof())
	{
		file >> number;
		l.addNode(number);
	}
	file.close();
	return true;
}

