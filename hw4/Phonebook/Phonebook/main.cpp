#define _CRT_SECURE_NO_WARNINGS
#include "Phonebook.h"
#include <stdio.h>

void tests();

int main()
{
	tests();

	return 0;
}

void tests()
{
	Phonebook p;
	Subscriber s1("Ololo", "1234");
	Subscriber s2("Tralala", "567");
	Subscriber s3("Lalala", "900");
	p.addNote(s1);
	p.addNote(s2);
	p.addNote(s3);
	p.findNumberByName("Tralala");
	printf("Test passed if written: Tralala 567\n");
	p.findNameByNumber("900");
	printf("Test passed if written: Lalala 900\n");
	p.printAllNotes();
	printf("Test passed if written:\n\"\n");
	printf("Ololo 1234\n");
	printf("Tralala 567\n");
	printf("Lalala 900\n\"\n");
	p.saveToFile();
	printf("Check file \"phonebook\" to finish testing\n");
}