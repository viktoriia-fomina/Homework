#include "Postfix.h"
#include "Stack.h"
#include <iostream>

using namespace std;

bool isOperator(char symbol);

int performOperation(char symbol, int firstNum, int secondNum);

int fromPostfixToResult(string const & str)
{
	Stack s;
	size_t sizeOfStr = str.size();
	for (size_t i = 0; i < sizeOfStr; ++i)
	{
		if (!isOperator(str[i]))
		{
			char number = str[i];
			int numberInInt = atoi(&number);
			s.push(numberInInt);
		}
		else if (!isOperator(str[i]))
		{
			if (s.peek() == -1)
			{
				cout << "Incorrect expression" << endl;
				return -1;
			}
			int num2 = s.peek();
			s.pop();
			if (s.peek() == -1)
			{
				cout << "Incorrect expression" << endl;
				return -1;
			}
			int num1 = s.peek();
			s.pop();
			int resultOfOperation = performOperation(str[i], num1, num2);
			s.push(resultOfOperation);
		}
		else
		{
			cout << "Incorrect expression" << endl;
			return -1;
		}
	}
	return s.peek();
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
	default:
		cout << "Incorrect expression" << endl;
		return -1;
	}
	return result;
}