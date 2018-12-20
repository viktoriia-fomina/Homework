#include "userInterface.h"
#include "List.h"
#include <fstream>
#include "Sort.h"

bool readFromFileAndSort(int const number);

using namespace std;

bool userInterface()
{
	while (true)
	{
		int number = 0;
		cout << endl << endl << "Input number:" << endl;
		cout << "0 - exit" << endl;
		cout << "1 - sort by names" << endl;
		cout << "2 - sort by phone numbers" << endl << endl;
		cin >> number;
		cout << endl;
		switch (number)
		{
		case 0:
			return true;
		case 1:
		case 2:
			if (!readFromFileAndSort(number))
			{
				return false;
			}
			break;
		default:
			cout << "There is no such an option" << endl;
			break;
		}
	}
	return true;
}

bool readFromFileAndSort(int const number)
{
	if (number != 1 && number != 2)
	{
		return false;
	}
	List l;
	ifstream file;
	file.open("forSort.txt", ios::in);
	if (!file.is_open())
	{
		cout << "File not found" << endl;
		return false;
	}
	string buffer;
	int numberOfWords = 0;
	while (!file.eof())
	{
		file >> buffer;
		if (numberOfWords % 2 == number - 1)
		{
			l.addNode(buffer);
		}
		++numberOfWords;
	}
	mergeSort();
	cout << l;
	file.close();
	return true;
}