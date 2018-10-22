// "Считалочка" – отряд из 41 - го сикария, защищавший галилейскую крепость Массада, 
// не пожелал сдаваться в плен блокировавшим его превосходящим силам римлян.
// Сикарии стали в круг и договорились, что каждые два воина будут убивать третьего, пока не погибнут все.
// Самоубийство – тяжкий грех, но тот, кто в конце концов останется последним, должен будет его совершить.
// Иосиф Флавий, командовавший этим отрядом, якобы быстро рассчитал, где нужно стать ему и его другу, 
// чтобы остаться последними, но не для того, чтобы убить друг друга, а чтобы сдать крепость римлянам.
// В нашем случае участвует n воинов и убивают каждого m - го.Требуется определить номер k начальной позиции воина, 
// который должен будет остаться последним.Считать с помощью циклического списка.

#include <iostream>

using namespace std;

int josephusProblem(int const numberOfWarriors, int const murderFrequency);
void tests();

int main()
{
	int n = 0;
	cout << "Input number of warriors\n";
	cin >> n;
	int m = 0;
	cout << "Input murder frequency\n";
	cin >> m;
	cout << "Safe position is " << josephusProblem(n, m) << endl;

	system("pause");
	return 0;
}

void tests()
{
	int numberOfTests = 0;
	int const cols = 5;
	int const rows = 5;
	int** array{};
	int count = 1;
	for (int i = 1; i <= rows; ++i)
	{
		for (int j = 1; j <= cols; ++j)
		{
			if (array[i][j] == josephusProblem(i, j))
			{
				cout << "Test " << count << " passed\n";
			}
			else
			{
				cout << "Test " << count << " FAILED\n";
				cout << "Input: " << i << ", " << j << endl;
				cout << "Output: " << josephusProblem(i, j) << endl;
				cout << "Right output: " << array[i][j] << endl << endl;
			}
			++count;
		}
	}
}