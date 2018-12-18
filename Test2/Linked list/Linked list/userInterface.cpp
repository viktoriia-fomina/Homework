#include "userInterface.h"
#include "List.h"
#include <iostream>

using namespace std;

//Написать программу, которая в диалоговом режиме позволяет осуществлять следующие операции :
//0 - выйти
//1 - добавить значение в заданную позицию в двусвязный список
//2 - удалить значение в заданной позиции из списка
//3 - распечатать список
//Позиции задаются целыми числами, 0 соответствует голове списка.

void case1(List & l);

void case2(List & l);

void case3(List const & l);

void userInterface()
{
	int number = 0;
	List l;
	while (true)
	{
		cout << "Input number:" << endl;
		cout << "0 - exit" << endl;
		cout << "1 - add element to position" << endl;
		cout << "2 - delete element from the position" << endl;
		cout << "3 - print list" << endl << endl;
		cin >> number;
		switch (number)
		{
		case 0:
			return;
		case 1:
			case1(l);
			break;
		}
	}
}

void case1(List & l)
{
	int position = 0;
	int data = 0;
	cout << "Input positon" << endl;
	cin >> position;
	cout << "Input data of an element" << endl;
	cin >> data;
	if (!l.addToPosition(position, data))
	{
		cout << "Element can not be added. Incorrect positon" << endl;
	}
}

void case2(List & l)
{
	int position = 0;
	cout << "Input positon" << endl;
	cin >> position;
	if (!l.deleteFromThePosition(position))
	{
		cout << "Element can not be deleted. Incorrect positon" << endl;
	}
}

void case3(List const & l)
{
	cout << l << endl;
}