#include "Problem.h"
#include <iostream>
#include "Pair.h"
#include <vector>

using namespace std;

void solution(vector<Pair> const & baseOfVisitors);

void problemAboutVisitors()
{
	cout << "Input information about visitors: hourStart, minuteStart, hourFinish, minuteFinish" << endl;
	cout << "When visitors are finished input -1" << endl;

	int hourStart = 0;
	int minuteStart = 0;
	int hourFinish = 0;
	int minuteFinish = 0;

	Pair* visitor = nullptr;
	vector<Pair> baseOfVisitors;

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
		baseOfVisitors.push_back(*visitor);
	}
}

void solution(vector<Pair> const & baseOfVisitors)
{
	int currentNumberOfVisitors = 0;
	int hourBeg = 0;
	int minuteBeg = 0;
	int hourFin = 0;
	int minuteFin = 0;
	int maxNumberOfVisitors;
	for (int i = 0; i < baseOfVisitors.size(); ++i)
	{

	}
}