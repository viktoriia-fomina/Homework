//�������� ��������� - ���������� ����������.��� ������ ����� ������� ����� � ������ ���������, 
//� ������������� ������ ������������ ��������� �������� :
//0 - �����
//1 - �������� ������(��� � �������)
//2 - ����������� ��� ��������� ������
//3 - ����� ������� �� �����
//4 - ����� ��� �� ��������
//5 - ��������� ������� ������ � ����
//��� ������� ��������� ������ ������ ������ �� �����, ���� ����� ��� - �������� � ������ ���� �������.
//������ ���� ��������� ������ �������.

#pragma once

struct Subscriber;

struct Phonebook
{
	// ������������ - ����������
	Phonebook();
	~Phonebook();

	// getter - setter
	Subscriber operator[](int number) const;
	Subscriber & operator[](int number);
	int size() const;

	// ��������� ������
	void addNote(Subscriber const & note); // 1
	void printAllNotes() const; // 2
	void findNumberByName(char const * name) const; // 3
	void findNameByNumber(char const * number) const; // 4
	int saveToFile() const; // 5
private:
	int readInfoFromFile(); // ��������������� ����� � ������������
	Phonebook(Phonebook const & p) = delete; // ����������� �����������
	void operator=(Phonebook const & p) = delete; // �������� ������������

	Subscriber* base;
	int numberOfNotes;
};