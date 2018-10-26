#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

// В некоторых языках программирования однострочные комментарии задаются не //, 
// как в С++, а символом ";" (комментарий начинается с ; и заканчивается концом строки). 
// Задача - вывести на консоль все комментарии такого вида из входного файла (вместе с символом ";"). 
// До комментария в строке может быть значимый текст, его выводить не надо. 
// Пустые строки выводить не надо.

int readComments();

int main()
{	
	readComments();

	return 0;
}

int readComments()
{
	ifstream file("test.txt", ios::in);
	if (!file.is_open())
	{
		cout << "File not found" << endl;
		return 1;
	}
	else
	{
		int const size = 100;
		char buffer[size]{};
		bool flagIfSymbol = false;
		while (!file.eof())
		{
			file.getline(buffer, size);
			int length = strlen(buffer);
			for (int i = 0; i < length; ++i)
			{
				if (flagIfSymbol)
				{
					cout << buffer[i];
				}
				if (buffer[i] == ';')
				{
					cout << ";";
					flagIfSymbol = true;
				}
			}
			if (flagIfSymbol)
			{
				cout << endl;
			}
			flagIfSymbol = false;
		}
		file.close();
	}
	return 0;
}