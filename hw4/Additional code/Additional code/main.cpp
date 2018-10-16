#include "Header.h"
#include "locale.h"

// Ввести два числа, перевести в двоичное представление в дополнительном коде и напечатать, 
// сложить в столбик в двоичном представлении, вывести сумму, перевести в десятичное, 
// вывести сумму в десятичном виде.Все сообщения писать по - русски(рекомендуется использовать функцию setlocale, 
// чтобы сообщения выводились по - русски и под Windows тоже).

int main()
{
	// это вместо тестов

	setlocale(LC_ALL, "Russian");
	int number1 = 0;
	printf("Введите первое число\n");
	scanf("%i", &number1);
	int number2 = 0;
	printf("Введите второе число\n");
	scanf("%i", &number2);
	auto num1 = additionalCode(number1);
	auto num2 = additionalCode(number2);
	printf("Первое число в дополнительном коде:\n");
	num1.print();
	printf("\n");
	printf("Второе число в дополнительном коде:\n");
	num2.print();
	printf("\n");
	auto sum = num1 + num2;
	printf("Сумма в дополнительном коде\n");
	sum.print();
	printf("\n");
	printf("Сумма в десятичной системе\n");
	sum.printInDecimalSystem();
	printf("\n");

	return 0;
}