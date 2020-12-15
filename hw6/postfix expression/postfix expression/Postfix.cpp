#include "Postfix.h"
#include "Stack.h"
#include <iostream>

using namespace std;

bool isOperator(char symbol);

int performOperation(char symbol, int firstNum, int secondNum);

pair<bool, int> & error(pair<bool, int> & p);

pair<bool, int> & fromPostfixToResult(string const & str, pair<bool, int> & p)
{
	Stack s;
	size_t const sizeOfStr = str.size();
	for (size_t i = 0; i < sizeOfStr; ++i)
	{
		if (!isOperator(str[i]))
		{
			if (!isdigit(str[i]))
			{
				cout << "Incorrect input" << endl;
				p.first = false;
				p.second = -1;
				return p;
			}
			char number = str[i];
			int numberInInt = atoi(&number);
			s.push(numberInInt);
		}
		else if (isOperator(str[i]))
		{
			if (!s.peek(p).first)
			{
				return error(p);
			}
			int num2 = s.peek(p).second;
			s.pop();
			if (!s.peek(p).first)
			{
				return error(p);
			}
			int num1 = s.peek(p).second;
			s.pop();
			int resultOfOperation = performOperation(str[i], num1, num2);
			s.push(resultOfOperation);
		}
		else
		{
			return error(p);
		}
	}
	p.first = s.peek(p).first;
	p.second = s.peek(p).second;
	return p;
}

pair<bool, int> & error(pair<bool, int> & p)
{
	p.first = false;
	cout << "Incorrect expression" << endl;
	p.second = -1;
	return p;
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