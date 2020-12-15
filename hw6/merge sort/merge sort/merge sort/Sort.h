#pragma once
#include <vector>

template<class Type, typename DataType, typename IndexType>
struct Sort
{
	void mergeSort(IndexType const & numberOfWord)
	{
		std::vector<Type> containerForMerge;
		containerForMerge.resize(size());
		mergeSortRecursion(0, size() - 1, containerForMerge, numberOfWord);
	}

protected:
	virtual Type & operator[](IndexType const & i) = 0;
	virtual IndexType size() const = 0;
	virtual DataType operator()(IndexType const & index, IndexType const & numberOfWord) = 0;

private:
	void mergeSortRecursion(IndexType first, IndexType last, std::vector<Type> & containerForMerge, 
			IndexType const & numberOfWord)
	{
		if (last - first > 0)
		{
			IndexType middle = (first + last) / 2;
			mergeSortRecursion(first, middle, containerForMerge, numberOfWord);
			mergeSortRecursion(middle + 1, last, containerForMerge, numberOfWord);
			merge(first, middle, middle + 1, last, containerForMerge, numberOfWord);
		}
	}

	void merge(IndexType first1, IndexType last1, IndexType first2, IndexType last2, std::vector<Type> & containerForMerge,
			IndexType const & numberOfWord)
	{
		IndexType iterator1 = first1;
		IndexType iterator2 = first2;
		IndexType position = 0;
		while (iterator1 < last1 + 1 && iterator2 < last2 + 1)
		{
			if ((*this)(iterator1, numberOfWord) < (*this)(iterator2, numberOfWord))
			{
				containerForMerge[position] = (*this)[iterator1];
				++iterator1;
			}
			else
			{
				containerForMerge[position] = (*this)[iterator2];
				++iterator2;
			}
			++position;
		}
		while (iterator1 < last1 + 1)
		{
			containerForMerge[position] = (*this)[iterator1];
			++iterator1;
			++position;
		}
		while (iterator2 < last2 + 1)
		{
			containerForMerge[position] = (*this)[iterator2];
			++iterator2;
			++position;
		}
		copyArrayToSortingArray(containerForMerge, first1, last2);
	}

	void copyArrayToSortingArray(std::vector<Type> const & containerForMerge, IndexType const & first1,
			IndexType const & last2)
	{
		IndexType iterator = first1;
		IndexType position = 0;
		while (iterator <= last2)
		{
			(*this)[iterator] = containerForMerge[position];
			++iterator;
			++position;
		}
	} 
};