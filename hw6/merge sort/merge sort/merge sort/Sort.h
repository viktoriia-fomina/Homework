#pragma once
#include <vector>

template<class Type, typename DataType, typename IndexType>
struct Sort
{
	void mergeSort(IndexType const & numberOfWord)
	{
		std::vector<Type> data;
		data.resize(size());
		mergeSortRecursion(0, size() - 1, data, numberOfWord);
	}

protected:
	virtual Type & operator[](IndexType const & i) = 0;
	virtual IndexType size() const = 0;
	virtual DataType operator()(IndexType const & index, IndexType const & numberOfWord) = 0;

private:
	void mergeSortRecursion(IndexType first, IndexType last, std::vector<Type> & data, IndexType const & numberOfWord)
	{
		if (last - first > 0)
		{
			IndexType middle = (first + last) / 2;
			mergeSortRecursion(first, middle, data, numberOfWord);
			mergeSortRecursion(middle + 1, last, data, numberOfWord);
			merge(first, middle, middle + 1, last, data, numberOfWord);
		}
	}

	void merge(IndexType first1, IndexType last1, IndexType first2, IndexType last2, std::vector<Type> & data,
			IndexType const & numberOfWord)
	{
		IndexType iterator1 = first1;
		IndexType iterator2 = first2;
		IndexType position = 0;
		while (iterator1 < last1 + 1 && iterator2 < last2 + 1)
		{
			if ((*this)(iterator1, numberOfWord) < (*this)(iterator2, numberOfWord))
			{
				data[position] = (*this)[iterator1];
				++iterator1;
			}
			else
			{
				data[position] = (*this)[iterator2];
				++iterator2;
			}
			++position;
		}
		while (iterator1 < last1 + 1)
		{
			data[position] = (*this)[iterator1];
			++iterator1;
			++position;
		}
		while (iterator2 < last2 + 1)
		{
			data[position] = (*this)[iterator2];
			++iterator2;
			++position;
		}
		copyArrayToSortingArray(data, first1, last2);
	}

	void copyArrayToSortingArray(std::vector<Type> const & data, IndexType const & first1, 
			IndexType const & last2)
	{
		IndexType iterator = first1;
		IndexType position = 0;
		while (iterator <= last2)
		{
			(*this)[iterator] = data[position];
			++iterator;
			++position;
		}
	} 
};