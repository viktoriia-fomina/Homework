#define _CRT_SECURE_NO_WARNINGS
#include "Phonebook.h"

#include <iostream>
#include <stdio.h>

int main()
{
	Phonebook p;
	Subscriber s("test", "12232");
	p.addNote(s);
	p.printAllNotes();
	
	system("pause");
	return 0;
}