#include "Infix to postfix.h"

bool isOperator(char const symbol);
bool isRoundBracket(char const symbol);
void doIfOperator(Stack & s, string & toPostrix, int & currentIndex, char const currentSymbol);
bool isPlusOrMinus(char const symbol);
bool isMultOrDiv(char const symbol); 

int infixToPostfix(string & infix, string & toPostfix)
{
	Stack s;
	int currentIndex = 0;
	for (int i = 0; i < (int)infix.size(); ++i)
	{
		if (!isOperator(infix[i]) && !isRoundBracket(infix[i]))
		{
			toPostfix[currentIndex] = infix[i];
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
				if (infix[i] == ')' && s.isEmpty())
				{
					cout << "Infix expression is incorrect" << endl;
					return -1;
				}
				else if (infix[i] == ')' && isOperator(s.peek()))
				{
					toPostfix[currentIndex] = s.peek();
					s.pop();
					++currentIndex;
					if (infix[i] == ')' && s.peek() == '(')
					{
						s.pop();
					}
				}
				else if (infix[i] == '(' && (s.isEmpty() || isOperator(s.peek()) || s.peek() == '('))
				{
					s.push(infix[i]);
				}
			}
		}
	}
	while (!s.isEmpty())
	{
		toPostfix[currentIndex] = s.peek();
		s.pop();
		++currentIndex;
	}
}

bool isOperator(char const symbol)
{
	return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

bool isRoundBracket(char const symbol)
{
	return (symbol == '(' || symbol == ')');
}

void doIfOperator(Stack & s, string & toPostrix, int & currentIndex, char const currentSymbol)
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
			// текущий символ умнож или дел, последний элемент на стеке - умножить или делить
			// текущий элемент плюс или минус, последний элемент на стеке - оператор
			toPostrix[currentIndex] = s.peek();
			s.pop();
			s.push(currentSymbol);
			++currentIndex;
		}
	}
}

bool isPlusOrMinus(char const symbol)
{
	return (symbol == '+' || symbol == '-');
}

bool isMultOrDiv(char const symbol)
{
	return (symbol == '*' || symbol == '/');
}