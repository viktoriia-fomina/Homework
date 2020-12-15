#pragma once
#include <utility>

struct Element;

struct Stack
{
	// �����������
	Stack();

	// ����������
	~Stack();

	// ���������� �������� � ������
	void push(int data);

	// �������� �������� �� ������
	bool pop();

	// ���������� �� �������� �������
	std::pair<bool, int> peek(std::pair<bool, int> & p) const;

	// ��������� �������� �� ���� ������
	bool isEmpty() const;
private:
	Element * head;
};