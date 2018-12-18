#include <iostream>
#include <fstream>
#include "readFromFile.h"
#include "hashTable.h"

using namespace std;

int main()
{
	ifstream file;
	file.open("text.txt", ios::in);
	HashTable * table = frequencyOfEveryWordInText(file);
	file.close();
	cout << table->averageSizeOfList() << endl;
	cout << table->loadFactor() << endl;
	cout << table->maxSizeOfList() << endl;

	return 0;
}