#include <iostream>
#include <fstream>
#include "readFromFile.h"
#include "hashTable.h"

using namespace std;

bool frequencyOfEveryWordInText(ifstream & file)
{
	if (!file.is_open())
	{
		cout << "File not found" << endl;
		return false;
	}
	HashTable s;
	char buffer[30]{};
	while (!file.eof())
	{
		file >> buffer;
		s.addElement(buffer);		
	}
	s.frequencyOfEveryWord();
	return true;
}