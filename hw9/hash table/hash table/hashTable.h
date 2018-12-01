#include <list>
#include <vector>

struct Set
{
	Set();

	void add(std::string const & str);

	void deleteElement(std::string const & str);

	bool exists(std::string const & str) const;

private:
	int hashFunction(std::string const & str) const;

	std::vector<std::list<std::string>> buckets;
};