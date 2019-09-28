// "Считалочка" – отряд из 41 - го сикария, защищавший галилейскую крепость Массада, 
// не пожелал сдаваться в плен блокировавшим его превосходящим силам римлян.
// Сикарии стали в круг и договорились, что каждые два воина будут убивать третьего, пока не погибнут все.
// Самоубийство – тяжкий грех, но тот, кто в конце концов останется последним, должен будет его совершить.
// Иосиф Флавий, командовавший этим отрядом, якобы быстро рассчитал, где нужно стать ему и его другу, 
// чтобы остаться последними, но не для того, чтобы убить друг друга, а чтобы сдать крепость римлянам.
// В нашем случае участвует n воинов и убивают каждого m - го.Требуется определить номер k начальной позиции воина, 
// который должен будет остаться последним.Считать с помощью циклического списка.

#include <iostream>
#include <fstream>

using namespace std;

int josephusProblem(int const numberOfWarriors, int const murderFrequency);
int tests();

int main()
{
	// этот закоменченный кусок кода для того, чтобы тестировать самостоятельно

	/*int n = 0;
	cout << "Input number of warriors\n";
	cin >> n;
	int m = 0;
	cout << "Input murder frequency\n";
	cin >> m;
	cout << "Safe position is " << josephusProblem(n, m) << endl;*/
	
	tests();

	return 0;
}

int tests()
{
	ifstream file("tests.txt");
	if (!file.is_open())
	{
		cout << "File could not be opened\n";
		return -1;
	}
	int numberOfString = 0;
	int const size = 10;
	int numbers[size]{};
	int count = 0;
	int number = 0;
	int numberOfTest = 1;
	while (!file.eof())
	{
		file >> number;
		numbers[count] = number;
		++count;
		if (count == size)
		{
			++numberOfString;
			for (int i = 0; i < size; ++i)
			{
				int result = josephusProblem(numberOfString, i + 1);
				if (result == numbers[i])
				{
					cout << "Test " << numberOfTest << " passed" << endl;
				}
				else
				{
					cout << "Test " << numberOfTest << " FAILED" << endl;
				}
				++numberOfTest;
			}
			count = 0;
		}
	}
	file.close();
	return 0;
}