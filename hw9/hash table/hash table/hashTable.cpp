#include "hashTable.h"
#include <algorithm>

//Посчитать частоты встречаемости слов в тексте с помощью хеш - таблицы.На входе файл с текстом, 
//вывести на консоль все слова, встречающиеся в этом тексте с количеством раз, которое встречается каждое слово.
//Словом считается последовательность символов, разделённая пробелами, разные словоформы считаются разными словами.
//Хеш - таблицу реализовать в отдельном модуле, использующем модуль "Список".Подсчитать и вывести также 
//коэффициент заполнения хеш - таблицы, максимальную и среднюю длину списка в сегменте таблицы.

Set::Set()
{
	int size = 100;
	buckets.resize(size);
}

void Set::addElement(std::string const & str)
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

double Set::loadFactor() const
{
	for (int i = 0; buckets.size(); ++i)
	{
		
	}
}