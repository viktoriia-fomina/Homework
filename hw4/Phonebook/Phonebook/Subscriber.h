#pragma once

struct Subscriber
{
	// ����������� - �������� ����������� - ����������
	Subscriber(char const * name, char const * number);
	Subscriber();
	Subscriber(Subscriber const & s);
	Subscriber & operator=(Subscriber const & s);
	~Subscriber();

	// getter - setter
	char const * getName() const;
	void setName(char const * name);
	char const * getNumber() const;
	void setNumber(char const * number);

	// ��������� ������
	void print() const;
private:
	void setStr(char const * str, char** destination);
	char* name;
	char* number;
};