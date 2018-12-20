#include "countries.h"
#include <iostream>

using namespace std;

void initializeCapitals(vector<set<int>> & countries);

void initializeFrontiers(Graph const & graph,
		vector<set<int>> const & countries, vector<set<int>> & countriesFrontiers);

vector<set<int>> countriesDivider(Graph const & graph)
{
	int numberOfCountries;
	cout << "Input number of countries : ";
	cin >> numberOfCountries;
	vector<set<int>> countries(numberOfCountries);
	initializeCapitals(countries);

	vector<set<int>> countriesFrontiers(numberOfCountries);
	initializeFrontiers(graph, countries, countriesFrontiers);

	return countries;
}

void initializeCapitals(vector<set<int>> & countries)
{
	int const numberOfCountries = countries.size();
	for (int country = 0; country < numberOfCountries; ++country)
	{
		cout << "Input the capital of the country " << country << endl;
		int capital;
		cin >> capital;
		countries[country].insert(capital);
	}
}

void initializeFrontiers(Graph const & graph,
		vector<set<int>> const & countries, vector<set<int>> & countriesFrontiers)
{

}