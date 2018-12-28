#include "List.h"
#include <iostream>
#include <vector>

using namespace std;

void problemAboutVisitors()
{
	List start;
	List end;
	int hour = 0;
	int minute = 0;
	cout << "Input hourStart minuteStart hourFinish minuteFinish" << endl;
	cout << "-1 to finish input" << endl;
	while (true)
	{
		cin >> hour;
		if (hour == -1)
		{
			break;
		}
		cin >> minute;
		minute += hour * 60;
		start.addElement(minute);
		cin >> hour;
		minute += hour * 60;
		end.addElement(minute);
	}
}

void calculateMax(List const & start, List const & end)
{
	int maxVisitors = 0;
	int currentNumOfVisitors = 0;
	int startIterator = 0;
	int endIterator = 0;
	while (startIterator != start.size() - 1 || endIterator != end.size() - 1)
	{
		if (start.getData(startIterator) < start.getData(endIterator))
		{
			++currentNumOfVisitors;
			if (currentNumOfVisitors > maxVisitors)
			{
				maxVisitors = currentNumOfVisitors;
			}
			++startIterator;
		}
		else if (start.getData(startIterator) < start.getData(endIterator))
		{
			--currentNumOfVisitors;
			++endIterator;
		}
	}
}