#include "hashTable.h"
#include <algorithm>

Set::Set()
{
	int size = 100;
	buckets.resize(size);
}

void Set::add(std::string const & str)
{
	if (!exists(str))
	{
		int hash = hashFunction(str) % buckets.size();
		buckets[hash].push_back(str);
	}
}

void Set::deleteElement(std::string const & str)
{
	if (exists(str))
	{
		int hash = hashFunction(str) % buckets.size();
		buckets[hash].remove(str);
	}
}

bool Set::exists(std::string const & str) const
{
	int hash = hashFunction(str) % buckets.size();
	return std::find(buckets[hash].begin(), buckets[hash].end(), str) !=
		buckets[hash].end();
}

int Set::hashFunction(std::string const & str) const
{
	int sum = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		sum += sum * 5 + str[i];
	}
	return sum;
}