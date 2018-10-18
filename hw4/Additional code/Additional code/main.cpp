#include "Header.h"
#include "locale.h"

// Ввести два числа, перевести в двоичное представление в дополнительном коде и напечатать, 
// сложить в столбик в двоичном представлении, вывести сумму, перевести в десятичное, 
// вывести сумму в десятичном виде.Все сообщения писать по - русски(рекомендуется использовать функцию setlocale, 
// чтобы сообщения выводились по - русски и под Windows тоже).

void tests();
bool test1();
bool test2();
bool test3();

int main()
{
	tests();
	printf("\n");
	setlocale(LC_ALL, "Russian");
	int number1 = 0;
	printf("Введите первое число\n");
	scanf("%i", &number1);
	int number2 = 0;
	printf("Введите второе число\n");
	scanf("%i", &number2);
	auto const num1 = additionalCode(number1);
	auto const num2 = additionalCode(number2);
	printf("Первое число в дополнительном коде:\n");
	num1.print();
	printf("\n");
	printf("Второе число в дополнительном коде:\n");
	num2.print();
	printf("\n");
	auto const sum = num1 + num2;
	printf("Сумма в дополнительном коде\n");
	sum.print();
	printf("\n");
	printf("Сумма в десятичной системе\n");
	sum.printInDecimalSystem();
	printf("\n");

	return 0;
}

void tests()
{
	bool const flagIfTest1Passed = test1();
	if (flagIfTest1Passed)
	{
		printf("Test 1 passed\n");
	}
	else
	{
		printf("Test 1 failed\nNumbers we tested on were 3 and 9\n");
	}

	bool const flagIfTest2Passed = test2();
	if (flagIfTest2Passed)
	{
		printf("Test 2 passed\n");
	}
	else
	{
		printf("Test 2 failed\nNumbers we tested on were 0 and 0\n");
	}

	bool const flagIfTest3Passed = test3();
	if (flagIfTest3Passed)
	{
		printf("Test 3 passed\n");
	}
	else
	{
		printf("Test 3 failed\nNumbers we tested on were -4 and 2\n");
	}
}

bool test1()
{
	int const number1 = 3;
	int const number2 = 9;
	auto const num1 = additionalCode(number1);
	auto const num2 = additionalCode(number2);
	bool flagIfTestPassed = true;
	// 3
	for (int i = 0; i < 30; ++i)
	{
		if (num1[i] != 0)
		{
			flagIfTestPassed = false;
			return flagIfTestPassed;
		}
	}
	if (num1[30] != 1 || num1[31] != 1)
	{
		flagIfTestPassed = false;
		return flagIfTestPassed;
	}
	// 9
	for (int i = 0; i < 28; ++i)
	{
		if (num2[i] != 0)
		{
			flagIfTestPassed = false;
			return flagIfTestPassed;
		}
	}
	if (num2[28] != 1 || num2[29] != 0 || num2[30] != 0 || num2[31] != 1)
	{
		flagIfTestPassed = false;
		return flagIfTestPassed;
	}
	auto const sum = num1 + num2;
	// 12
	for (int i = 0; i < 28; ++i)
	{
		if (sum[i] != 0)
		{
			flagIfTestPassed = false;
			return flagIfTestPassed;
		}
	}
	if (sum[28] != 1 || sum[29] != 1 || sum[30] != 0 || sum[31] != 0)
	{
		flagIfTestPassed = false;
		return flagIfTestPassed;
	}
	int const sumInDecimal = sum.toDecimalSystem();
	if (sumInDecimal != 12)
	{
		flagIfTestPassed = false;
		return flagIfTestPassed;
	}
	return flagIfTestPassed;
}

bool test2()
{
	int const number1 = 0;
	int const number2 = 0;
	auto const num1 = additionalCode(number1);
	auto const num2 = additionalCode(number2);
	bool flagIfTestPassed = true;
	// 0
	for (int i = 0; i < 32; ++i)
	{
		if (num1[i] != 0)
		{
			flagIfTestPassed = false;
			return flagIfTestPassed;
		}
	}
	// 0
	for (int i = 0; i < 32; ++i)
	{
		if (num2[i] != 0)
		{
			flagIfTestPassed = false;
			return flagIfTestPassed;
		}
	}
	auto const sum = num1 + num2;
	// 0
	for (int i = 0; i < 32; ++i)
	{
		if (sum[i] != 0)
		{
			flagIfTestPassed = false;
			return flagIfTestPassed;
		}
	}
	int const sumInDecimal = sum.toDecimalSystem();
	if (sumInDecimal != 0)
	{
		flagIfTestPassed = false;
		return flagIfTestPassed;
	}
	return flagIfTestPassed;
}

bool test3()
{
	int const number1 = -4;
	int const number2 = 2;
	auto const num1 = additionalCode(number1);
	auto const num2 = additionalCode(number2);
	bool flagIfTestPassed = true;
	// -4
	for (int i = 0; i < 30; ++i)
	{
		if (num1[i] != 1)
		{
			flagIfTestPassed = false;
			return flagIfTestPassed;
		}
	}
	if (num1[30] != 0 || num1[31] != 0)
	{
		flagIfTestPassed = false;
		return flagIfTestPassed;
	}
	// 2
	for (int i = 0; i < 30; ++i)
	{
		if (num2[i] != 0)
		{
			flagIfTestPassed = false;
			return flagIfTestPassed;
		}
	}
	if (num2[30] != 1 || num2[31] != 0)
	{
		flagIfTestPassed = false;
		return flagIfTestPassed;
	}
	auto const sum = num1 + num2;
	// -2
	for (int i = 0; i < 31; ++i)
	{
		if (sum[i] != 1)
		{
			flagIfTestPassed = false;
			return flagIfTestPassed;
		}
	}
	if (sum[31] != 0)
	{
		flagIfTestPassed = false;
		return flagIfTestPassed;
	}
	int const sumInDecimal = sum.toDecimalSystem();
	if (sumInDecimal != -2)
	{
		flagIfTestPassed = false;
		return flagIfTestPassed;
	}
	return flagIfTestPassed;
}