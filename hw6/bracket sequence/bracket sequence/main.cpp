#include "Stack.h"
#include "bracket sequence.h"
#include <string>
#include <iostream>
#include "tests.h"

// �������� ��������� �������� ������� ������ � ������, ������ ����� ���� ��� ����� 
// : (), [], {}.��������� ������������������ ����({ ) } ��������� ������������, ({}) - ����������.

using namespace std;

int main()
{
	tests();
	string s;
	cout << "Input string" << endl;
	cin >> s;
	bool result = ifBracketSequenceIsCorrect(s);
	cout << "res is " << result << endl;

	return 0;
}