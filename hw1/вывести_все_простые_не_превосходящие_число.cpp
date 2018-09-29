#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("Input number : ");
	int number = 0;
	scanf("%i", &number);
	int count = 0;
	for (int i = 2; i <= number; ++i)
	{
		count = 0;
		for (int j = 2; j <= sqrt(i); ++j)
		{
			if (i % j == 0)
			{
				count = 1;
				break;
			}
		}
		if (count == 0)
		{
			printf("%i\ ", i);
		}
	}
	printf("\n");
	return 0;
}