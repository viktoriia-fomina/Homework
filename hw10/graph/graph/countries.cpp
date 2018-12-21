#include "countries.h"
#include <set>
#include <vector>
#include "graph.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <cassert>

using namespace std;

void getDataFromFile(Graph & graph, vector<set<int>> & countries,
		set<int> & unvisitedCities, string const & filename);

void initializeCountriesFromFile(vector<set<int>> & countries,
		set<int> & unvisitedCities, ifstream & file);

void countriesDivider(Graph const & graph, vector<set<int>> & countries, set<int> & unvisitedCities);

void addCityToCountry(set<int> & country, set<int> & unvisitedCities, Graph const & graph);

void printCountries(vector<set<int>> const & countries);

vector<set<int>> mainFunc(string const & filename)
{
	// создаём пустые контейнеры для данных
	Graph graph;
	vector<set<int>> countries;
	set<int> unvisitedCities;

	// инициализация данных
	getDataFromFile(graph, countries, unvisitedCities, filename);

	// основной алгоритм, добавление городов в страны
	countriesDivider(graph, countries, unvisitedCities);

	// вывод результата
	printCountries(countries);
	return countries;
}

void getDataFromFile(Graph & graph, vector<set<int>> & countries,
	set<int> & unvisitedCities, string const & filename)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cout << "File not found" << endl;
		return;
	}

	// ввод городов и расстояний между ними
	int numberOfCities;
	file >> numberOfCities;
	assert(numberOfCities > 0);
	graph.resize(numberOfCities);
	int numberOfEdges;
	file >> numberOfEdges;
	bool numberOfEdgesIsCorrect =
			(numberOfEdges == ((numberOfCities * numberOfCities - numberOfCities) / 2));
	assert(numberOfEdgesIsCorrect);
	for (int edge = 0; edge < numberOfEdges; ++edge)
	{
		int row;
		file >> row;
		int column;
		file >> column;
		file >> graph.edgeWeight(row, column);
		graph.edgeWeight(column, row) = graph.edgeWeight(row, column);
	}
	graph.symmetricAdjacencyMatrix();

	// ввод количества стран и их столиц, инициализация стран и непосещённых городов
	int numberOfCountries;
	file >> numberOfCountries;
	assert(numberOfCountries > 0 && numberOfCountries <= numberOfCities);
	countries.resize(numberOfCountries);
	unvisitedCities = graph.getSetOfVertexes();

	// пихаем столицы в страны и удаляем столицы из непосещённых
	initializeCountriesFromFile(countries, unvisitedCities, file);
	file.close();
}

void initializeCountriesFromFile(vector<set<int>> & countries,
		set<int> & unvisitedCities, ifstream & file)
{
	for (int country = 0; country < countries.size(); ++country)
	{
		int capital;
		file >> capital;
		bool capitalIsInUnvisited = true;
		if (unvisitedCities.count(capital) == 0)
		{
			capitalIsInUnvisited = false;
		}
		assert(capitalIsInUnvisited);
		countries[country].insert(capital);
		unvisitedCities.erase(capital);
	}
}

void countriesDivider(Graph const & graph, vector<set<int>> & countries, set<int> & unvisitedCities)
{
	int country = 0;
	while (!unvisitedCities.empty())
	{
		addCityToCountry(countries[country], unvisitedCities, graph);
		++country;
		country %= countries.size();
	}
}

void addCityToCountry(set<int> & country, set<int> & unvisitedCities, Graph const & graph)
{
	int minDistance = INT_MAX;
	int cityToAdd = -1;
	for (set<int>::iterator cityInCountry = country.begin();
			cityInCountry != country.end(); ++cityInCountry)
	{
		for (set<int>::iterator unvisitedCity = unvisitedCities.begin();
				unvisitedCity != unvisitedCities.end(); ++unvisitedCity)
		{
			int const currentDistance = graph.edgeWeight(*cityInCountry, *unvisitedCity);
			if (currentDistance != 0 && currentDistance <= minDistance)
			{
				minDistance = currentDistance;
				cityToAdd = *unvisitedCity;
			}
		}
	}
	if (cityToAdd != -1)
	{
		country.insert(cityToAdd);
		unvisitedCities.erase(cityToAdd);
	}
}

void printCountries(vector<set<int>> const & countries)
{
	for (int country = 0; country < countries.size(); ++country)
	{
		cout << "Country: " << country << endl;
		for (set<int>::iterator city = countries[country].begin();
				city != countries[country].end(); ++city)
		{
			cout << *city << " ";
		}
		cout << endl;
	}
}