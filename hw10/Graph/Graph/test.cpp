#include "test.h"
#include "countries.h"
#include <vector>
#include <set>
#include <iostream>

using namespace std;

void tests()
{
	vector<set<int>> answer1;
	answer1.resize(3);
	answer1[0] = set<int>{ 0, 3, 4 };
	answer1[1] = set<int>{ 1, 5 };
	answer1[2] = set<int>{ 2, 6 };
	if (countriesSeparator("data.txt") == answer1)
	{
		cout << endl << "Test1 passed" << endl;
	}
}