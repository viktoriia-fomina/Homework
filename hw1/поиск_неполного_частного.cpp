#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

bool error(int b);
int checkSign(int a, int b);
int result(int a, int b);

int main()
{
	int a = 0;
	int b = 0;
	printf("Input divident : ");
	scanf("%i", &a);
	printf("Input divider : ");
	scanf("%i", &b);

	if (error(b))
	{
		printf("Division by zero is not allowed!\n");
		return 0;
	}
	printf("Result is %i\n", checkSign(a, b) * result(abs(a), abs(b)));
	return 0;
}

bool error(int b)
{
	return b == 0;
}

int checkSign(int a, int b)
{
	if (a * b < 0)
		return -1;
	else
		return 1;
}

int result(int a, int b)
{
	int result = 0;
	while (a >= b)
	{
		a -= b;
		result++;
	}
	return result;
}