#include <iostream>
#include <fstream>
#include "readFromFile.h"
#include "hashTable.h"

using namespace std;

HashTable * frequencyOfEveryWordInText(ifstream & file)
{
	HashTable* s = new HashTable();
	if (!file.is_open())
	{
		cout << "File not found" << endl;
		return s;
	}
	char buffer[30]{};
	while (!file.eof())
	{
		file >> buffer;
		s->addElement(buffer);		
	}
	s->frequencyOfEveryWord();
	return s;
}