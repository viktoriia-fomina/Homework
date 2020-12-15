﻿#include "toPostfix.h"

bool isOperator(char const symbol);
bool isRoundBracket(char const symbol);
void doIfOperator(Stack & s, string & toPostrix, int & currentIndex, char const currentSymbol);
int doIfRoundBracket(Stack & s, string & toPostfix, int & currentIndex, char const currentSymbol);
int popAllOperators(Stack & s, string & toPostfix, int & currentIndex);
bool isPlusOrMinus(char const symbol);
bool isMultOrDiv(char const symbol);

int toPostfix(string const & infix, string & toPostfix)
{
	Stack s;
	int currentIndex = 0;
	for (int i = 0; i < (int)infix.size(); ++i)
	{
		if (!isOperator(infix[i]) && !isRoundBracket(infix[i]))
		{
			toPostfix += infix[i];
			++currentIndex;
		}
		else
		{
			if (isOperator(infix[i]))
			{
				doIfOperator(s, toPostfix, currentIndex, infix[i]);
			}
			else
			{
				if (doIfRoundBracket(s, toPostfix, currentIndex, infix[i]) == -1)
				{
					cout << "Infix expression is incorrect" << endl;
					return -1;
				}
			}
		}
	}
	while (!s.isEmpty())
	{
		if (popAllOperators(s, toPostfix, currentIndex) == -1)
		{
			return -1;
		}
	}
	return 0;
}

bool isOperator(char const symbol)
{
	return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

bool isRoundBracket(char const symbol)
{
	return (symbol == '(' || symbol == ')');
}

void doIfOperator(Stack & s, string & toPostfix, int & currentIndex, char const currentSymbol)
{
	if (s.isEmpty())
	{
		s.push(currentSymbol);
	}
	else
	{
		if (isMultOrDiv(currentSymbol) && isPlusOrMinus(s.peek()) || s.peek() == ')')
		{
			s.push(currentSymbol);
		}
		else if (s.peek() == '(')
		{
			s.push(currentSymbol);
		}
		else
		{
			// òåêóùèé ñèìâîë óìíîæ èëè äåë, ïîñëåäíèé ýëåìåíò íà ñòåêå - óìíîæèòü èëè äåëèòü
			// òåêóùèé ýëåìåíò ïëþñ èëè ìèíóñ, ïîñëåäíèé ýëåìåíò íà ñòåêå - îïåðàòîð
			toPostfix += s.peek();
			++currentIndex;
			s.pop();
			s.push(currentSymbol);
		}
	}
}

int doIfRoundBracket(Stack & s, string & toPostfix, int & currentIndex, char const currentSymbol)
{
	if (currentSymbol == ')' && s.isEmpty())
	{
		return -1;
	}
	else if (currentSymbol == ')' && isOperator(s.peek()))
	{
		toPostfix += s.peek();
		++currentIndex;
		s.pop();
		if (s.peek() == '(')
		{
			s.pop();
		}
	}
	else
	{
		// åñëè ñêîáêà êðóãëàÿ, òî ïðîñòî êëàäåì åå â ñòåê
		s.push(currentSymbol);
	}
	return 0;
}

int popAllOperators(Stack & s, string & toPostfix, int & currentIndex)
{
	if (isRoundBracket(s.peek()))
	{
		return -1;
	}
	toPostfix += s.peek();
	++currentIndex;
	s.pop();
	return 0;
}

bool isPlusOrMinus(char const symbol)
{
	return (symbol == '+' || symbol == '-');
}

bool isMultOrDiv(char const symbol)
{
	return (symbol == '*' || symbol == '/');
}