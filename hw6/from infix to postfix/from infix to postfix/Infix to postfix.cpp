#include "Infix to postfix.h"

bool isOperator(char const symbol);
bool ifOperatorHasHigherPriority(char const operatorCheck, char const operatorCompareWith, 
		bool wasOpeningBrake);

void infixToPostfix(string & infix, string & toPostfix)
{
	Stack s;
	int count = 0;
	// bool wasOpeningBrake = false;
	for (int i = 0; i < (int)infix.size(); ++i)
	{
		if (!isOperator(infix[i]))
		{
			toPostfix[count] = infix[i];
			++count;
		}
		else if (infix[i] == '(' || infix[i] == ')')
		{
			/*if (infix[i] == '(')
			{
				wasOpeningBrake = true;
			}
			else
			{
				wasOpeningBrake = false;
			}*/
		}
		else
		{
			
			while (!s.isEmpty())
			{
				if (ifOperatorHasHigherPriority(infix[i], s.peek()))
				{
					break;
				}
				else
				{
					toPostfix[count] = s.peek();
					s.pop();
					++count;
				}
			}
			s.push(infix[i]);
		}
	}
	while (!s.isEmpty())
	{
		toPostfix[count] = s.peek();
		s.pop();
	}
}

bool isOperator(char const symbol)
{
	return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

bool ifOperatorHasHigherPriority(char const operatorCheck, char const operatorCompareWith,
		bool wasOpeningBrake)
{
	if (!wasOpeningBrake)
	{
		if (operatorCheck == '+' || operatorCheck == '-')
		{
			return false;
		}
		else
		{
			if (operatorCompareWith == '*' || operatorCompareWith == '/')
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	else
	{

	}
}