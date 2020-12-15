#pragma once
#include <iostream>

using namespace std;

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
	int pop();
	// ���������� �� �������� �������
	char peek();
	// ��������� �������� �� ���� ������
	bool isEmpty();
private:
	Element * head;
};