#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	Set s;
	s.addValueByKey("krasivaya", "vika");
	s.addValueByKey("umnii", "vitalik");
	//s.addValueByKey("dobrya", "mama");
	s.print();
	cout << endl;
	s.addValueByKey("necshastnii", "kotik");
	//s.addValueByKey("amazing", "tralala");
	s.print();

	return 0;
}