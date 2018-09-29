#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	float x = 0;
	printf("Input x : ");
	scanf("%f", &x);
	float t = x * x;
	float result = t * (t + x + 1) + x + 1;
	printf("Result is %f\n", result);
	return 0;
}