#pragma once

struct CompareInterface
{
	virtual bool operator<(CompareInterface const & c) const = 0;

	bool operator>(CompareInterface const & c) const;

	bool operator<=(CompareInterface const & c) const;

	bool operator>=(CompareInterface const & c) const;

	bool operator==(CompareInterface const & c) const;
};