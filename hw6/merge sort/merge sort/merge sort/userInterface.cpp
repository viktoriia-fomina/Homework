#include "userInterface.h"
#include "List.h"
#include <fstream>
#include "Sort.h"
#include <cassert>
#include "ForStrings.h"

bool readFromFileAndSort(int const numberOfWordByWhichToSort);

using namespace std;

bool userInterface()
{
	while (true)
	{
		int number = 0;
		cout << "Input number:" << endl;
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
			if (!readFromFileAndSort(1))
			{
				cout << "Error" << endl;
				return false;
			}
			break;
		case 2:
			if (!readFromFileAndSort(2))
			{
				cout << "Error" << endl;
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

bool readFromFileAndSort(int const numberOfWordByWhichToSort)
{
	assert(numberOfWordByWhichToSort == 1 || numberOfWordByWhichToSort == 2);
	List l;
	ifstream file;
	file.open("dataToSort.txt", ios::in);
	if (!file.is_open())
	{
		cout << "File not found" << endl;
		return false;
	}
	string buffer;
	string firstWord;
	string secondWord;
	int numberOfWords = 1;
	int whichWordToSet = 0;
	while (!file.eof())
	{
		file >> buffer;
		if (numberOfWords % 2 == 1)
		{
			firstWord = buffer;
		}
		else
		{
			secondWord = buffer;
			l.addNode(firstWord, secondWord);
		}
		++numberOfWords;
	}
	l.mergeSort(numberOfWordByWhichToSort);
	cout << l;
	file.close();
	return true;
}