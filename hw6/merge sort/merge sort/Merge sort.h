#pragma once
#include "Compare interface.h"

template<typename dataType, typename indexType, typename sizeType>
class Sort
{
	virtual sizeType getSize() const = 0;
	virtual dataType & operator(indexType const i)[] = 0;
	void mergeSort()
	{

	}
};