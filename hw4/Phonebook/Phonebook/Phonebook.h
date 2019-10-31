//Ќаписать программу - телефонный справочник.ќна должна уметь хранить имена и номера телефонов, 
//в интерактивном режиме осуществл€ть следующие операции :
//0 - выйти
//1 - добавить запись(им€ и телефон)
//2 - распечатать все имеющиес€ записи
//3 - найти телефон по имени
//4 - найти им€ по телефону
//5 - сохранить текущие данные в файл
//ѕри запуске программа должна читать данные из файла, если файла нет - начинать с пустой базы номеров.
//–азмер базы ограничен сотней записей.

#pragma once

struct Subscriber;

struct Phonebook
{
	// конструкторы - деструктор
	Phonebook();
	~Phonebook();

	// getter - setter
	Subscriber operator[](int number) const;
	Subscriber & operator[](int number);
	int size() const;

	// остальные методы
	void addNote(Subscriber const & note); // 1
	void printAllNotes() const; // 2
	void findNumberByName(char const * name) const; // 3
	void findNameByNumber(char const * number) const; // 4
	int saveToFile() const; // 5
private:
	int readInfoFromFile(); // вспомогательный метод к конструктору
	Phonebook(Phonebook const & p) = delete; // конструктор копировани€
	void operator=(Phonebook const & p) = delete; // оператор присваивани€

	Subscriber* base;
	int numberOfNotes;
};