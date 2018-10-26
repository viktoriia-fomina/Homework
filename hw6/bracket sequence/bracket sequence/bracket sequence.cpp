#include "bracket sequence.h"

bool isBracket(char const symbol);
bool ifClosingBracket(char const symbol);
bool ifOpeningBracket(Stack & s, char const symbol);
bool ifPairOfBrackets(Stack & s, char const closingBracket);

bool ifBracketSequenceIsCorrect(string const & str)
{
	Stack s;
	for (int i = 0; i < str.size(); ++i)
	{
		if (isBracket(str[i]))
		{
			if (s.isEmpty())
			{
				if (!ifOpeningBracket(s, str[i]))
				{
					return false;
				}
			}
			else
			{
				if (ifClosingBracket(str[i]))
				{
					if (ifClosingBracket(s.peek()))
					{
						return false;
					}
					if (!ifPairOfBrackets(s, str[i]))
					{
						return false;
					}
				}
				else
				{
					s.push(str[i]);
				}
			}
		}
	}
	if (!s.isEmpty())
	{
		return false;
	}
	return true;
}

bool isBracket(char const symbol)
{
	return (symbol == '(' || symbol == ')' || symbol == '[' || symbol == ']' ||
			symbol == '{' || symbol == '}');
}

bool ifClosingBracket(char const symbol)
{
	return (symbol == ')' || symbol == ']' || symbol == '}');
}

bool ifOpeningBracket(Stack & s, char const symbol)
{
	if (symbol == '(' || symbol == '[' || symbol == '{')
	{
		s.push(symbol);
		return true;
	}
	else
	{
		return false;
	}
}

bool ifPairOfBrackets(Stack & s, char const closingBracket)
{
	if (s.peek() == '(' && closingBracket == ')')
	{
		s.pop();
		return true;
	}
	if (s.peek() == '[' && closingBracket == ']')
	{
		s.pop();
		return true;
	}
	if (s.peek() == '{' && closingBracket == '}')
	{
		s.pop();
		return true;
	}
	return false;
}