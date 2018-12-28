#include "Problem.h"
#include <iostream>
#include "DataBase.h"
#include "Pair.h"

using namespace std;

void problemAboutVisitors()
{
	cout << "Input information about visitors: hourStart, minuteStart, hourFinish, minuteFinish" << endl;
	cout << "When visitors are finished input -1" << endl;

	int hourStart = 0;
	int minuteStart = 0;
	int hourFinish = 0;
	int minuteFinish = 0;

	Pair* visitor = nullptr;
	DataBase baseOfVisitors;

	while (true)
	{
		cin >> hourStart;
		if (hourStart == -1)
		{
			break;
		}
		visitor = new Pair;
		visitor->hourStart = hourStart;
		cin >> minuteStart;
		visitor->minuteStart = minuteStart;
		cin >> hourFinish;
		visitor->hourFinish = hourFinish;
		cin >> minuteFinish;
		visitor->minuteFinish = minuteFinish;
		baseOfVisitors.addVisitior(*visitor);
	}
}