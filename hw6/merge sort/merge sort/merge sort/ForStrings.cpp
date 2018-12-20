#include "forStrings.h"

using namespace std;

string * firstPartOfStr(string const & str)
{
	string* firstPart;
	int position = 0;
	while (str[position] != ' ')
	{
		firstPart += str[position];
		++position;
	}
	return firstPart;
}

string * secondPartOfStr(string const & str)
{
	string* secondPart;
	int position = 0;
	while (str[position] != ' ')
	{
		++position;
	}
	++position;
	while (position < str.size())
	{
		secondPart += str[position];
	}
}

bool ifPartsIsStr(std::string const & str, std::string & const part1, std::string & const part2)
{
	int position = 0;
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