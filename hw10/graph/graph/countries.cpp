#include "countries.h"
#include <iostream>

using namespace std;

void initializeCapitals(vector<set<int>> & countries);

void initializeFrontiers(Graph const & graph,
		vector<set<int>> const & countries, vector<set<int>> & countriesFrontiers);

void deleteForeignCitiesFromFrontiers(vector<set<int>> const & countries, 
		vector<set<int>> & countriesFrontiers);

bool allFrontiersAreEmpty(vector<set<int>> const & countriesFrontiers);

vector<set<int>> countriesDivider(Graph const & graph)
{
	int numberOfCountries;
	cout << "Input number of countries : ";
	cin >> numberOfCountries;
	vector<set<int>> countries(numberOfCountries);
	initializeCapitals(countries);

	vector<set<int>> countriesFrontiers(numberOfCountries);
	initializeFrontiers(graph, countries, countriesFrontiers);
	
	bool exit = allFrontiersAreEmpty(countriesFrontiers);

	while (!exit)
	{
		/*for (int country = 0; country < countries.size(); ++country)
		{
			int distance = graph.edgeWeight(*countriesFrontiers[country].begin(), countries[country].begin());
			for (set<int>::iterator frontierCity = countriesFrontiers[country].begin();
					frontierCity != countriesFrontiers[country].end(); ++frontierCity)
			{

			}
		}*/
		exit = allFrontiersAreEmpty(countriesFrontiers);
	}

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
	for (int country = 0; country < countries.size(); ++country)
	{
		countriesFrontiers[country] = graph.subGraphFrontier(countries[country]);
	}
	deleteForeignCitiesFromFrontiers(countries, countriesFrontiers);
}

void deleteForeignCitiesFromFrontiers(vector<set<int>> const & countries,
		vector<set<int>> & countriesFrontiers)
{
	// бежим по странам, потом бежим по границам стран, затем проверяем, есть ли город из границы в какой-либо стране
	for (int country = 0; country < countries.size(); ++country)
	{
		for (set<int>::iterator frontierCity = countriesFrontiers[country].begin();
				frontierCity != countriesFrontiers[country].end(); ++frontierCity)
		{
			for (int i = 0; i < countries.size(); ++i)
			{
				if (countries[i].find(*frontierCity) != countries[i].end())
				{
					countriesFrontiers[country].erase(frontierCity);
				}
			}
		}
	}
}

bool allFrontiersAreEmpty(vector<set<int>> const & countriesFrontiers)
{
	bool exit = true;
	for (int country = 0; country < countriesFrontiers.size(); ++country)
	{
		exit = exit && countriesFrontiers[country].empty();
	}
	return exit;
}