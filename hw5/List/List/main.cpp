//Написать программу, которая в диалоговом режиме позволяет осуществлять следующие операции :
//0 – выйти
//1 – добавить значение в сортированный список
//2 – удалить значение из списка
//3 – распечатать список
//Все операции должны сохранять сортированность.Начинаем с пустого списка.

#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List l;
	l.addNode(1);
	l.addNode(2);
	l.addNode(3);
	l.addNode(0);
	// cout << l << endl;
	l.deleteNode(2);
	l.deleteNode(1);
	l.deleteNode(3);
	l.deleteNode(0);
	l.deleteNode(2);
	cout << l << endl;
	

	// auto* temp = l.getHeadPtr();


	system("pause");
	return 0;
}