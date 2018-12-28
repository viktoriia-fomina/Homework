#include "List.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int calculateMax(List const & start, List const & end);

void findMaxInter(List const & start, List const & end, int maxVisitors);

bool readFromFile(string const & fileName, List & start, List & end);

void problemAboutVisitors()
{
	List start;
	List end;
	if (!readFromFile("input.txt", start, end))
	{
		return;
	}
	findMaxInter(start, end, calculateMax(start, end));
}

int calculateMax(List const & start, List const & end)
{
	int maxVisitors = 0;
	int currentNumOfVisitors = 0;
	int startIterator = 0;
	int endIterator = 0;
	while (startIterator < start.size() && endIterator < end.size())
	{
		if (start.getData(startIterator) < end.getData(endIterator))
		{
			++currentNumOfVisitors;
			if (currentNumOfVisitors > maxVisitors)
			{
				maxVisitors = currentNumOfVisitors;
			}
			++startIterator;
		}
		else if (start.getData(startIterator) < end.getData(endIterator))
		{
			--currentNumOfVisitors;
			++endIterator;
		}
	}
	return maxVisitors;
}

void findMaxInter(List const & start, List const & end, int maxVisitors)
{
	int currentNumOfVisitors = 0;
	int startIterator = 0;
	int endIterator = 0;
	int timeBeg = 0;
	int timeEnd = 0;
	while (startIterator < start.size() && endIterator < end.size())
	{
		if (start.getData(startIterator) < end.getData(endIterator))
		{
			++currentNumOfVisitors;
			if (currentNumOfVisitors == maxVisitors)
			{
				maxVisitors = currentNumOfVisitors;
				timeBeg = start.getData(startIterator);
			}
			++startIterator;
		}
		else if (start.getData(startIterator) < end.getData(endIterator))
		{
			if (currentNumOfVisitors == maxVisitors)
			--currentNumOfVisitors;
			++endIterator;
		}
	}
	if (timeEnd == 0)
	{
		timeEnd = end.getData(end.size() - 1);
	}
	int minBeg = timeBeg % 60;
	int hourBeg = timeBeg / 60;
	int minEnd = timeEnd % 60;
	int hourEnd = timeEnd / 60;
	cout << hourBeg << ":" << minBeg << " - " << hourEnd << ":" << minEnd << endl;
}

bool readFromFile(string const & fileName, List & start, List & end)
{
	ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		cout << "File not found" << endl;
		return false;
	}
	int hour = 0;
	int minute = 0;
	while (!file.eof())
	{
		file >> hour;
		if (hour == -1)
		{
			break;
		}
		file >> minute;
		minute += hour * 60;
		start.addElement(minute);
		file >> hour;
		file >> minute;
		minute += hour * 60;
		end.addElement(minute);
	}
	file.close();
	return true;
}