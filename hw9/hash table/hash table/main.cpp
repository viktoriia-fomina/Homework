#include <iostream>
#include <fstream>
#include "readFromFile.h"
#include "hashTable.h"

using namespace std;

int main()
{
	Set s;
	s.addElement("lala");
	s.addElement("ololo");
	s.addElement("lol");
	s.addElement("trala");
	s.addElement("lala");
	s.addElement("ololo");
	s.addElement("ololo");
	cout << s.loadFactor() << endl;
	s.frequencyOfEveryWord();
	cout << s.averageSizeOfList() << endl;

	ifstream file;
	file.open("text.txt", ios::in);
	frequencyOfEveryWordInText(file);
	file.close();

	return 0;
}