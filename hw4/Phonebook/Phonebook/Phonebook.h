//Написать программу - телефонный справочник.Она должна уметь хранить имена и номера телефонов, 
//в интерактивном режиме осуществлять следующие операции :
//0 - выйти
//1 - добавить запись(имя и телефон)
//2 - распечатать все имеющиеся записи
//3 - найти телефон по имени
//4 - найти имя по телефону
//5 - сохранить текущие данные в файл
//При запуске программа должна читать данные из файла, если файла нет - начинать с пустой базы номеров.
//Размер базы ограничен сотней записей.

#pragma once
#include <stdio.h>
#include <string.h>

struct Subscriber
{
	explicit Subscriber(char* name, char* number);
	Subscriber();
	Subscriber(Subscriber const & s);
	~Subscriber();
	void getName();
	void getNumber();
private:
	char* name;
	char* number;
};

struct Phonebook
{
	Phonebook();
	~Phonebook();
	void addNote(Subscriber const & s); // 1
	void printAllNotes() const; // 2
	void findNumberByName(char* name) const; // 3
	void findNameByNumber(int* number, int sizeOfNumber) const; // 4
	void saveCurrentDataToFile() const; // 5
private:
	Subscriber* base;
	int numberOfNotes;
};