#include "countries.h"
#include <set>
#include <vector>
#include "graph.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <cassert>

using namespace std;

bool getDataFromFile(Graph & graph, vector<set<int>> & countries,
	set<int> & unvisitedCities, string const filename);

void initializeCountriesFromFile(vector<set<int>> & countries,
	set<int> & unvisitedCities, ifstream & file);

void countriesDivider(Graph const & graph, vector<set<int>> & countries, set<int> & unvisitedCities);

void addCityToCountry(set<int> & country, set<int> & unvisitedCities, Graph const & graph);

void printCountries(vector<set<int>> const & countries);

vector<set<int>> countriesSeparator(string const filename)
{
	//создаём пустые контейнеры для данных
	Graph graph;
	vector<set<int>> countries;
	set<int> unvisitedCities;

	//инициализация данных
	bool fileIsNotOpen = getDataFromFile(graph, countries, unvisitedCities, filename);
	if (!fileIsNotOpen)
	{
		cout << "File is not open!!!";
		return countries;
	}

	// основной алгоритм, добавление городов в страны
	countriesDivider(graph, countries, unvisitedCities);

	// вывод результата
	printCountries(countries);
	return countries;
}

bool getDataFromFile(Graph & graph, vector<set<int>> & countries,
	set<int> & unvisitedCities, string const filename)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		return false;
	}

	// ввод городов и расстояний между ними
	int numberOfCities;
	file >> numberOfCities;
	assert(numberOfCities > 0);
	graph.resize(numberOfCities);
	int numberOfEdges;
	file >> numberOfEdges;
	for (int edge = 0; edge < numberOfEdges; ++edge)
	{
		int row;
		file >> row;
		int column;
		file >> column;
		file >> graph.edgeWeight(row, column);
		graph.edgeWeight(column, row) = graph.edgeWeight(row, column);
	}
	graph.symmetricAndNoLoopsAdjacencyMatrix();

	// ввод количества стран и их столиц, инициализация стран и непосещённых городов
	int numberOfCountries;
	file >> numberOfCountries;
	assert(numberOfCountries > 0 && numberOfCountries <= numberOfCities);
	countries.resize(numberOfCountries);
	unvisitedCities = graph.getSetOfVertexes();

	// пихаем столицы в страны и удаляем столицы из непосещённых
	initializeCountriesFromFile(countries, unvisitedCities, file);
	file.close();
	return true;
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