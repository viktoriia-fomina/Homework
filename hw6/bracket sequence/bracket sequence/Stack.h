#pragma once

struct Element;

struct Stack
{
	// �����������
	Stack();

	// ����������
	~Stack();

	// ���������� �������� � ������
	void push(char data);

	// �������� �������� �� ������
	bool pop();

	// ���������� �� �������� �������
	char peek() const;

	// ��������� �������� �� ���� ������
	bool isEmpty() const;
private:
	Element* head;
};