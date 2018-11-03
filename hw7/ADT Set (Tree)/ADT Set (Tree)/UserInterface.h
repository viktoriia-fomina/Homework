#pragma once
#include <iostream>
#include "Set.h"

using namespace std;

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
			int value = 0;
			cout << "Input value of the element" << endl;
			cin >> value;
			bool flagIfElementWasAdded = s.add(value);
			if (!flagIfElementWasAdded)
			{
				cout << "Element with that value is already in the set" << endl;
			}
		}
		else if (number == 2)
		{
			int value = 0;
			cout << "Input value of the element" << endl;
			cin >> value;
			bool flagIfNothingToRemove = s.remove(value);
			if (!flagIfNothingToRemove)
			{
				cout << "Element with that value was not found" << endl;
			}
		}
		else if (number == 3)
		{

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
	cout << "5 - print elements in descending order" << endl;
}