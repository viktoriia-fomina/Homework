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

vector<set<int>> countriesSeparator(string const filename);