#define _CRT_SECURE_NO_WARNINGS
#include "Phonebook.h"

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	Phonebook p;
	Subscriber s1("Vika", "1234");
	Subscriber s2("Vitalik", "567");
	p.addNote(s1);
	p.addNote(s2);
	p.findNumberByName("Vitalik");
	p.printAllNotes();
	
	system("pause");
	return 0;
}