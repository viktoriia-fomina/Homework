#pragma once
#include <vector>
#include "List.h"

void mergeSort(List const & dataToSort, int const size);


void mergeSortRecursion(int const first, int const last, List & dataToSort, vector<Node> & tempContainer);

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
			IndexType const & last2,  IndexType & iteratorOfPart, IndexType & i)
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
		IndexType iter = first1;
		IndexType j = 0;
		while (iter <= last2)
		{
			(*this)[iter] = data[j];
			++iter;
			++j;
		}
	}
};