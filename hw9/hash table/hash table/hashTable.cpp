#include "hashTable.h"
#include <algorithm>
#include <string>
#include <iostream>
#include "List.h"

using namespace std;

//��������� ������� ������������� ���� � ������ � ������� ��� - �������. �� ����� ���� � �������, 
//������� �� ������� ��� �����, ������������� � ���� ������ � ����������� ���, ������� ����������� ������ �����.
//������ ��������� ������������������ ��������, ���������� ���������, ������ ���������� ��������� ������� �������.
//��� - ������� ����������� � ��������� ������, ������������ ������ "������". ���������� � ������� ����� 
//����������� ���������� ��� - �������, ������������ � ������� ����� ������ � �������� �������.

HashTable::HashTable()
{
	int size = 100;
	buckets.resize(size);
}

void HashTable::addElement(std::string const & str)
{
	int hash = abs(hashFunction(str) % size());
	buckets[hash].addElement(str);
}

void HashTable::deleteElement(std::string const & str)
{
	if (exists(str))
	{
		int hash = abs(hashFunction(str) % size());
		buckets[hash].deleteElement(str);
	}
}

bool HashTable::exists(std::string const & str) const
{
	int hash = abs(hashFunction(str) % size());
	return buckets[hash].exists(str);
}

int HashTable::hashFunction(std::string const & str) const
{
	int sum = 0;
	for (size_t i = 0; i < str.size(); ++i)
	{
		sum += sum * 5 + str[i];
	}
	return sum;
}

double HashTable::loadFactor() const
{
	int sum = numberOfElements();
	return (double)sum / size();
}

int HashTable::numberOfElements() const
{
	int sum = 0;
	for (int i = 0; i < size(); ++i)
	{
		sum += buckets[i].size();
	}
	return sum;
}

int HashTable::maxSizeOfList() const
{
	int max = 0;
	for (int i = 0; i < size(); ++i)
	{
		if (buckets[i].size() > max)
		{
			max = buckets[i].size();
		}
	}
	return max;
}

double HashTable::averageSizeOfList() const
{
	int sum = 0;
	for (int i = 0; i < size(); ++i)
	{
		sum += buckets[i].size();
	}
	return double(sum) / size();
}

int HashTable::size() const
{
	return buckets.size();
}

void HashTable::frequencyOfEveryWord()
{
	for (int i = 0; i < size(); ++i)
	{
		if (!buckets[i].isEmpty())
		{
			for (int j = 0; j < buckets[i].size(); ++j)
			{
				buckets[i].printData(j);
				cout << endl;
			}
		}
	}
}