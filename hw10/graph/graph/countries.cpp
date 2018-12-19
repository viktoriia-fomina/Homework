#include "countries.h"
#include <iostream>

using namespace std;

vector<set<int>> countriesDivider(Graph const & graph)
{
	int numberOfCountries;
	cout << "Input number of countries : ";
	cin >> numberOfCountries;
	vector<set<int>> countries(numberOfCountries);
	for (int country = 0; country < numberOfCountries; ++country)
	{
		cout << "Input the capital of the country " << country << endl;
		int capital;
		cin >> capital;
		countries[country].insert(capital);
	}
	return countries;
}