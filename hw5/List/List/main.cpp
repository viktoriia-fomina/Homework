//Написать программу, которая в диалоговом режиме позволяет осуществлять следующие операции :
//0 – выйти
//1 – добавить значение в сортированный список
//2 – удалить значение из списка
//3 – распечатать список
//Все операции должны сохранять сортированность.Начинаем с пустого списка.

#include <iostream>
#include "List.h"

using namespace std;

void forUsers();

int main()
{
	forUsers();
	
	return 0;
}

void forUsers()
{
	List l;
	while (true)
	{
		cout << "INPUT NUMBER:\n";
		cout << "0 - exit\n";
		cout << "1 - add node\n";
		cout << "2 - delete node\n";
		cout << "3 - print list\n\n";
		int number = 0;
		cin >> number;
		if (number == 0)
		{
			break;
		}
		else if (number == 1)
		{
			int value = 0;
			cout << "Input value of node (integer)\n";
			cin >> value;
			l.addNode(value);
		}
		else if (number == 2)
		{
			int value = 0;
			cout << "Input value of node (integer)\n";
			cin >> value;
			l.deleteNode(value);
		}
		else if (number == 3)
		{
			cout << l << endl;
		}
		else
		{
			cout << "There is no number " << number << " in menu\n\n";
		}
	}
}