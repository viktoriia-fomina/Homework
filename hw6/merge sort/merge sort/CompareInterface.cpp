#include "CompareInterface.h"

bool CompareInterface::operator>(CompareInterface const & c) const
{
	return c < (*this);
}

bool CompareInterface::operator<=(CompareInterface const & c) const
{
	return !((*this) > c);
}

bool CompareInterface::operator>=(CompareInterface const & c) const
{
	return !((*this) < c);
}

bool CompareInterface::operator==(CompareInterface const & c) const
{
	return ((*this) >= c && (*this) <= c);
}