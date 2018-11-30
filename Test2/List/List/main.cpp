#include <iostream>
#include "List.h"
#include "readFromFile.h" 

using namespace std;

int main()
{
	List l;
	writeToList(l);
	bool flagIfSymmetric = true;
	for (int i = 0; i < l.size() / 2; ++i)
	{
		if (l[i] != l[l.size() - i - 1])
		{
			flagIfSymmetric = false;
			break;
		}
	}
	if (flagIfSymmetric)
	{
		cout << "List is symmetric" << endl;
	}
	else
	{
		cout << "List is not symmetric" << endl;
	}

	return 0;
}