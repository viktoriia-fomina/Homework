#include "readFromFile.h"
#include <fstream>
#include <iostream>
#include "hashTable.h"

using namespace std;

bool frequencyOfEveryWordInText()
{
	ifstream file;
	file.open("text.txt", ios::in);
	if (!file.is_open)
	{
		cout << "File not found" << endl;
		return false;
	}
	Set s;
	char buffer[30]{};
	while (!file.eof())
	{
		file >> buffer;
		s.addElement(buffer);		
	}
	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = 0; j < )
	}
}