#include <iostream>
#include "graph.h"
#include <set>

using namespace std;

int main()
{
	Graph g(6);
	cin >> g;
	set<int> sg;
	sg.insert(3);
	set<int> fr = g.subGraphFrontier(sg);
	for (set<int>::iterator i = fr.begin(); i != fr.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
	sg.insert(4);
	fr = g.subGraphFrontier(sg);
	for (set<int>::iterator i = fr.begin(); i != fr.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
	return 0;
}