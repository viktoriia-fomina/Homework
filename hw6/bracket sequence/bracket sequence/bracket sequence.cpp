#include "bracket sequence.h"

bool isBracket(char const symbol);
bool ifClosingBracket(char const symbol);
bool ifOpeningBracket(char const symbol);
bool ifPairOfBrackets(char const openingBracket, char const closingBracket);

bool ifBracketSequenceIsCorrect(string const & str)
{
	Stack s;
	for (int i = 0; i < str.size(); ++i)
	{
		if (isBracket(str[i]))
		{
			if (s.isEmpty())
			{
				if (ifOpeningBracket(str[i]))
				{
					s.push(str[i]);
				}
				else
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
					if (ifPairOfBrackets(s.peek(), str[i]))
					{
						s.pop();
					}
					else
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

bool ifOpeningBracket(char const symbol)
{
	if (symbol == '(' || symbol == '[' || symbol == '{')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ifPairOfBrackets(char const openingBracket, char const closingBracket)
{
	if (openingBracket == '(' && closingBracket == ')')
	{
		return true;
	}
	if (openingBracket == '[' && closingBracket == ']')
	{
		return true;
	}
	if (openingBracket == '{' && closingBracket == '}')
	{
		return true;
	}
	return false;
}