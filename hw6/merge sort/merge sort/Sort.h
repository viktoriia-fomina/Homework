#pragma once

template<typename DataType, typename IndexType>
struct Sort
{
	void mergeSort(IndexType first, IndexType last)
	{
		if (last - first > 0)
		{
			IndexType middle = (first + last) / 2;
			mergeSort(first, middle);
			mergeSort(middle + 1, last);
			merge(first, middle, middle + 1, last);
		}
	}

protected:
	virtual DataType & operator[](IndexType const & i) = 0;

private:
	void merge(IndexType first1, IndexType last1, IndexType first2, IndexType last2)
	{
		DataType* data = new DataType[last2 - first1 + 1]{};
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
		copyArrayToSortedArray()
		delete[] data;
	}

	void ifOneArrayIsEnded(DataType data[], IndexType const & first1,
			IndexType const & last2,  IndexType & iteratorOfPart, IndexType & i)
	{
		while (i < last2 - first1 + 1)
		{
			data[i] = (*this)[iteratorOfPart];
			++iteratorOfPart;
			++i;
		}
	}

	void copyArrayToSortingArray(DataType const data[], IndexType const & first1,
			IndexType const & last1, IndexType const & last2)
	{
		IndexType iter = first1;
		IndexType j = 0;
		copyPartOfArray(data[], iter, j, last1);
		copyPartOfArray(data[], iter, j, last2);
	}

	void copyPartOfArray(DataType const data[], IndexType & iter, IndexType & j,
			IndexType const & last)
	{
		while (iter <= last)
		{
			(*this)[iter] = data[j];
			++iter;
			++j;
		}
	}
};