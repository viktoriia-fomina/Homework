#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	Set s;
	s.addValueByKey("ama", "ololo");
	s.addValueByKey("baba", "blolo");
	s.addValueByKey("gaga", "crololo");
	string str1 = s.getValueByKey("gaga");
	cout << str1 << endl;
	string str2 = s.getValueByKey("ama");
	string str3 = s.getValueByKey("baba");
	cout << str2 << " " << str3 << endl;
	cout << s.keyExists("ama") << " " << s.keyExists("baba") << " " << s.keyExists("gaga") << endl;

	return 0;
}