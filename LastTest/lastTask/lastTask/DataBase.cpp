#include "DataBase.h"
#include "Pair.h"
#include <iostream>

void DataBase::addVisitior(Pair const & visitor)
{
	base.push_back(visitor);
}