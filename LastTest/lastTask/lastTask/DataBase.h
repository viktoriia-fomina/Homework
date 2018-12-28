#pragma once
#include <vector>

struct Pair;

struct DataBase
{
	void addVisitior(Pair const & visitor);
	std::vector<Pair> base;
};