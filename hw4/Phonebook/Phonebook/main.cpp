#define _CRT_SECURE_NO_WARNINGS
#include "Phonebook.h"
#include <stdio.h>

#include <iostream>

void tests();
void menu();

int main()
{
	// помимо интерактивного режима для пользователя есть тесты
	// в мейне не стала вызывать функцию тестс - посчитала лишним
	
	menu();

	system("pause");
	return 0;
}

void tests()
{	Phonebook p;
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

void menu()
{
	Phonebook p;
	int const size = 20;
	while (true)
	{
		printf("INPUT NUMBER:\n");
		printf("0 - exit\n");
		printf("1 - add note (name and phone)\n");
		printf("2 - print all notes\n");
		printf("3 - find phone number by name\n");
		printf("4 - find name by phone number\n");
		printf("5 - save data to file\n\n");
		int number = 0;
		scanf("%i", &number);
		if (number == 0)
		{
			break;
		}
		else if (number == 1)
		{
			char* name = new char[size];
			printf("Input name\n");
			scanf("%s", name);
			char* number = new char[size];
			printf("Input number\n");
			scanf("%s", number);
			printf("\n");
			p.addNote(Subscriber(name, number));
			delete[] name;
			delete[] number;
		}
		else if (number == 2)
		{
			p.printAllNotes();
			printf("\n");
		}
		else if (number == 3)
		{
			char* name = new char[size];
			printf("Input name\n");
			scanf("%s", name);
			printf("\n");
			p.findNumberByName(name);
			delete[] name;
		}
		else if (number == 4)
		{
			char* number = new char[size];
			printf("Input number\n\n");
			scanf("%s", number);
			printf("\n");
			p.findNameByNumber(number);
			delete[] number;
		}
		else if (number == 5)
		{
			p.saveToFile();
			printf("Saved\n\n");
		}
		else
		{
			printf("Data is incorrect\n\n");
		}
	}
}