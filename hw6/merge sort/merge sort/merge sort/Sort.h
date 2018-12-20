#pragma once
#include <vector>

template<class DataType, typename IndexType>
struct Sort
{
	void mergeSort()
	{
		std::vector<DataType> data;
		data.resize(size());
		mergeSortRecursion(0, size() - 1, data);
	}

protected:
	virtual DataType & operator[](IndexType const & i) = 0;
	virtual IndexType size() const = 0;

private:
	void mergeSortRecursion(IndexType first, IndexType last, std::vector<DataType> & data)
	{
		if (last - first > 0)
		{
			IndexType middle = (first + last) / 2;
			mergeSortRecursion(first, middle, data);
			mergeSortRecursion(middle + 1, last, data);
			merge(first, middle, middle + 1, last, data);
		}
	}

	void merge(IndexType first1, IndexType last1, IndexType first2, IndexType last2, std::vector<DataType> & data)
	{
		IndexType iterator1 = first1;
		IndexType iterator2 = first2;
		for (IndexType i = 0; i < last2 - first1 + 1; ++i)
		{
			if (iterator1 == last1 + 1 || iterator2 == last2 + 1)
			{
				if (iterator1 == last1 + 1)
				{
					ifOneArrayIsEnded(data, first1, last2, iterator2, i);
				}
				else
				{
					ifOneArrayIsEnded(data, first1, last2, iterator1, i);
				}
				break;
			}
			if ((*this)[iterator1] < (*this)[iterator2])
			{
				data[i] = (*this)[iterator1];
				++iterator1;
			}
			else
			{
				data[i] = (*this)[iterator2];
				++iterator2;
			}
		}
		copyArrayToSortingArray(data, first1, last2);
	}

	void ifOneArrayIsEnded(std::vector<DataType> & data, IndexType const & first1,
		IndexType const & last2, IndexType & iteratorOfPart, IndexType & i)
	{
		while (i < last2 - first1 + 1)
		{
			data[i] = (*this)[iteratorOfPart];
			++iteratorOfPart;
			++i;
		}
	}

	void copyArrayToSortingArray(std::vector<DataType> const & data, IndexType const & first1, 
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