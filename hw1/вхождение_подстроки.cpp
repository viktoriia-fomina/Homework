#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Заданы две строки : S и S1.Найти количество вхождений S1 в S как подстроки.

int func(int firstWeCheck, int S_size, int S1_size, char* S, char* S1, int & result);

int main()
{
	int S_size = 5;
	int S1_size = 1;
	printf("Input size of the main string : ");
	//scanf("%i", &S_size);
	printf("Input size of substring : ");
	//scanf("%i", &S1_size);
	char* S = new char[S_size];
	S[0] = '0';
	S[1] = '1';
	S[2] = '0';
	S[3] = '2';
	S[4] = '3';
	printf("Input the main string\n");
	//scanf("%s", S);
	char* S1 = new char[S1_size];// {0, 1};
	printf("Input substring\n");
	S1[0] = '0';
	//S1[1] = '0';
	//scanf("%s", S1);
	int result = 0;
	//cout << S << endl << S1;
	if (func(0, S_size, S1_size, S, S1, result) != -1)
	{
		int temp = func(0, S_size, S1_size, S, S1, result);
		while (temp <= S_size)
		{
			temp = func(temp, S_size, S1_size, S, S1, result);
		}
	}
	printf("Substring was found %i times\n", result);
	delete[] S;
	delete[] S1;
	return 0;
}

int func(int firstWeCheck, int S_size, int S1_size, char* S, char* S1, int & result)
{
	if (S_size - firstWeCheck < S1_size || S_size - 1 < firstWeCheck)
	{
		return S_size + 1;
	}
	int count = 0;
	for (int i = firstWeCheck; i < firstWeCheck + S1_size; i++)
	{
		if (S[i] == S1[count])
		{
			count++;
		}
		else
		{
			count = 0;
			if (S[i] == S1[count])
			{
				count++;
			}
		}
		if (count == S1_size)
		{
			result++;
			return i + 1;
		}
	}
	return firstWeCheck + 1;
}