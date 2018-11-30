#include "List.h"
#include <fstream>

using namespace std;

void writeFromList(ofstream & file, List & l);

bool writeToLists(int a, int b, List & l1, List & l2, List & l3)
{
	ifstream file;
	file.open("f.txt", ios::in);
	if (!file.is_open())
	{
		cout << "File not found" << endl;
		return false;
	}
	int number = 0;
	while (!file.eof())
	{
		file >> number;
		if (number < a)
		{
			l1.addNode(number);
		}
		else if (number >= a && number <= b)
		{
			l2.addNode(number);
		}
		else
		{
			l3.addNode(number);
		}
	}
	file.close();
	return true;
}

bool writeFromListsToFile(List & l1, List & l2, List & l3)
{
	ofstream file;
	file.open("g.txt");
	if (!file.is_open())
	{
		cout << "File not found" << endl;
		return false;
	}
	writeFromList(file, l1);
	writeFromList(file, l2);
	writeFromList(file, l3);	

	file.close();
	return true;
}

void writeFromList(ofstream & file, List & l)
{
	int buffer = 0;
	int iterator = l.size() - 1;
	while (!l.isEmpty())
	{
		buffer = l.getNumber(iterator);
		--iterator;
		file << buffer;
		file << " ";
	}
}