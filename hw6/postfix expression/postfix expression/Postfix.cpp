#include "Postfix.h"
#include "Stack.h"

bool isOperator(char symbol);
int performOperation(char symbol, int firstNum, int secondNum);

int fromPostfixToResult(string const & str)
{
	Stack s;
	int sizeOfStr = (int)str.size();
	for (int i = 0; i < sizeOfStr; ++i)
	{
		if (!isOperator(str[i]))
		{
			char number = str[i];
			int numberInInt = atoi(&number);
			s.push(numberInInt);
		}
		else
		{
			int num2 = s.peek();
			s.pop();
			int num1 = s.peek();
			s.pop();
			int resultOfOperation = performOperation(str[i], num1, num2);
			s.push(resultOfOperation);
		}
	}
	int result = s.peek();
	return result;
}

bool isOperator(char symbol)
{
	return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

int performOperation(char symbol, int firstNum, int secondNum)
{
	int result = 0;
	switch (symbol)
	{
	case '+':
		result = firstNum + secondNum;
		break;
	case '-':
		result = firstNum - secondNum;
		break;
	case '*':
		result = firstNum * secondNum;
		break;
	case '/':
		result = firstNum / secondNum;
		break;
	}
	return result;
}