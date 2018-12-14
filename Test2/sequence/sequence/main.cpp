#include <iostream>
#include "List.h"

//Написать программу, которая вводит с клавиатуры набор целых чисел(в любом порядке, конец — число 0), 
//и выводящую числа из этого набора в порядке возрастания и без повторений, с указанием того, сколько каждое число 
//раз встретилось в этом наборе.

using namespace std;

int main()
{
	int number = 1;
	List l;
	cout << "Input numbers. 0 - is symbol of the end of input" << endl;
	while (number != 0)
	{
		cin >> number;
		if (number != 0)
		{
			l.addElement(number);
		}
	}
	l.sort();
	cout << l << endl;

	return 0;
}