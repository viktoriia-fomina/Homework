#define _CRT_SECURE_NO_WARNINGS
#include "Phonebook.h"

#include <iostream>
#include <stdio.h>

int main()
{
	char* name = new char[5];
	for (int i = 0; i < 4; ++i)
	{
		scanf("%c", &name[i]);
	}
	name[4] = '\0';
	char* number = new char[5];
	for (int i = 0; i < 4; ++i)
	{
		scanf("%c", &number[i]);
	}
	number[4] = '\0';
	Subscriber a(name, number);
	a.getName();
	system("pause");
	a.getNumber();
	Subscriber b(name, number);
	Phonebook p;
	p.addNote(a);
	p.addNote(b);
	p.printAllNotes();
	


	
	system("pause");
	return 0;
}