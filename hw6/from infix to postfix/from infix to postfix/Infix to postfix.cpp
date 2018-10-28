#include "Infix to postfix.h"

bool isOperator(char const symbol);
bool ifOperatorHasHigherPriority(char const operatorCheck, char const operatorCompareWith, 
		bool wasOpeningBrake);

void infixToPostfix(string & infix, string & toPostfix)
{
	Stack s;
	
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