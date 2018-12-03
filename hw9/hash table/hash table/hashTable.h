#include <list>
#include <vector>

struct Set
{
	Set();

	void addElement(std::string const & str);

	double loadFactor() const;

	void deleteElement(std::string const & str);

	bool exists(std::string const & str) const;

private:
	int hashFunction(std::string const & str) const;

	std::vector<std::list<std::string>> buckets;
};