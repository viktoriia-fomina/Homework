#include "Sort.h"

using namespace std;

void mergeSort(List & dataToSort, int const size)
{
	std::vector<Node> tempContainer;
	tempContainer.resize(size);
	mergeSortRecursion(0, - 1, dataToSort, tempContainer);
}

void mergeSortRecursion(int const first, int const last, List & dataToSort, vector<Node> & tempContainer)
{
	if (last - first > 0)
	{
		int middle = (first + last) / 2;
		mergeSortRecursion(first, middle, dataToSort, tempContainer);
		mergeSortRecursion(middle + 1, last, dataToSort, tempContainer);
		merge(first, middle, middle + 1, last, data);
	}
}

void merge(int first1, int last1, int first2, int last2, List & dataToSort, vector<Node> & tempContainer)
{
	int iterator1 = first1;
	int iterator2 = first2;
	for (int i = 0; i < last2 - first1 + 1; ++i)
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
		if (l[iterator1] < (*this)[iterator2])
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