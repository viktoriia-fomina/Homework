#include "UserInterface.h"
#include <iostream>
#include "Set.h"

using namespace std;

void userCommands();
void case1(int const number, Set & s);
void case2(int const number, Set & s);
void case3(int const number, Set const & s);

void userInterface()
{
	int number = 0;
	Set s;
	while (true)
	{
		userCommands();
		cin >> number;
		if (number == 0)
		{
			break;
		}
		else if (number == 1)
		{
			case1(number, s);
		}
		else if (number == 2)
		{
			case2(number, s);
		}
		else if (number == 3)
		{
			case3(number, s);
		}
		else if (number == 4)
		{
			s.printInAscendingOrder();
			cout << endl << endl;
		}
		else if (number == 5)
		{
			s.printInDescendingOrder();
			cout << endl << endl;
		}
		else
		{
			cout << "There is no such menu option: " << number << endl << endl;
		}
	}
}

void userCommands()
{
	cout << "Input number:" << endl;
	cout << "0 - exit" << endl;
	cout << "1 - add value to the set" << endl;
	cout << "2 - delete value from the set" << endl;
	cout << "3 - check if value is in the set" << endl;
	cout << "4 - print elements in ascending order" << endl;
	cout << "5 - print elements in descending order" << endl << endl;
}

void case1(int const number, Set & s)
{
	int value = 0;
	cout << "Input value of the element" << endl;
	cin >> value;
	if (!s.add(value))
	{
		cout << "Element with that value is already in the set" << endl << endl;
	}
}

void case2(int const number, Set & s)
{
	int value = 0;
	cout << "Input value of the element" << endl;
	cin >> value;
	if (!s.remove(value))
	{
		cout << "Element with that value was not found" << endl << endl;
	}
}

void case3(int const number, Set const & s)
{
	int value = 0;
	cout << "Input value of the element" << endl;
	cin >> value;
	if (s.exists(value))
	{
		cout << "Element with that value is in the set" << endl << endl;
	}
	else
	{
		cout << "Element with that value is not in the set" << endl << endl;
	}
}