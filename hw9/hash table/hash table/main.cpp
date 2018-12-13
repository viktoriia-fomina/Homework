#include <iostream>
#include "hashTable.h"

using namespace std;

int main()
{
	Set s;
	s.addElement("lala");
	s.addElement("ololo");
	s.addElement("lol");
	s.addElement("trala");
	cout << s.loadFactor() << endl;

	return 0;
}