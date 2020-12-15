#include "forStrings.h"
#include <cassert>

using namespace std;

string firstPartOfStr(string const & str)
{
	assert(str.find(' ') != string::npos);
	assert(str.find(' ') != str.size() - 1);
	string firstPart;
	int position = 0;
	while (str[position] != ' ')
	{
		firstPart += str[position];
		++position;
	}
	return firstPart;
}

string secondPartOfStr(string const & str)
{
	assert(str.find(' ') != string::npos);
	assert(str.find(' ') != str.size() - 1);
	string secondPart;
	size_t position = 0;
	while (str[position] != ' ')
	{
		++position;
	}
	++position;
	while (position < str.size())
	{
		secondPart += str[position];
		++position;
	}
	return secondPart;
}

bool ifSubstrings(std::string const & str, std::string const & part1, std::string const & part2)
{
	assert(str.find(' ') != string::npos);
	assert(str.find(' ') != str.size() - 1);
	size_t position = 0;
	bool partsIsStr = true;
	while (str[position] != ' ')
	{
		if (str[position] != part1[position])
		{
			partsIsStr = false;
			return partsIsStr;
		}
		++position;
	}
	++position;
	int iteratorForSecondPart = 0;
	while (position < str.size())
	{
		if (str[position] != part2[iteratorForSecondPart])
		{
			partsIsStr = false;
			return partsIsStr;
		}
		++position;
		++iteratorForSecondPart;
	}
	return partsIsStr;
}