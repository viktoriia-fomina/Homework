#pragma once

template<typename dataType, typename indexType>
class Sort
{
	virtual indexType getSize() const = 0;
	virtual dataType & operator(indexType const i)[] = 0;
	void mergeSort(indexType first, indexType last)
	{
		indexType const size = getSize();
		
	}
};