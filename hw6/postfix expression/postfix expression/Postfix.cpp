#include "Postfix.h"
#include "Stack.h"

bool isOperator(char symbol);
int performOperation(char symbol, int firstNum, int secondNum);

int fromPostfixToResult(string const & str)
{
	Stack s;
	for (int i = 0; i < str.size(); ++i)
	{
		if (!isOperator(str[i]))
		{
			s.push(str[i]);
		}
		else
		{
			auto temp2 = s.peek();
			int num2 = atoi(&temp2);
			s.pop();
			auto temp1 = s.peek();
			int num1 = atoi(&temp1);
			s.pop();
			int resultOfOperation = performOperation(str[i], num1, num2);
			s.push(resultOfOperation);
		}
	}
	return str[str.size() - 1];
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