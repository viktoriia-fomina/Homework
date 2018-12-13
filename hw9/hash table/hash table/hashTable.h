#include <vector>

struct List;

struct Set
{
	Set();

	void addElement(std::string const & str);

	int maxSizeOfList() const;

	int size() const;

	void frequencyOfEveryWord();

	double averageSizeOfList() const;

	double loadFactor() const;

	void deleteElement(std::string const & str);

	bool exists(std::string const & str) const;

private:
	int hashFunction(std::string const & str) const;

	int numberOfElements() const;

	std::vector<List> buckets;
};