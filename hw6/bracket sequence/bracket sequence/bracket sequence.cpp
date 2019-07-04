#include "bracket sequence.h"
#include "Stack.h"

bool isBracket(char const symbol);
bool ifClosingBracket(char const symbol);
bool ifOpeningBracket(char const symbol);
bool ifPairOfBrackets(char const openingBracket, char const closingBracket);

bool ifBracketSequenceIsCorrect(std::string const & str)
{
	Stack s;
	for (int i = 0; i < str.size(); ++i)
	{
		if (isBracket(str[i]))
		{
			if (s.isEmpty())
			{
				if (!ifOpeningBracket(str[i]))
				{
					return false;
				}
				s.push(str[i]);
			}
			else
			{
				if (ifClosingBracket(str[i]))
				{
					if (!ifPairOfBrackets(s.peek(), str[i]))
					{
						return false;
					}
					s.pop();
				}
				else
				{
					s.push(str[i]);
				}
			}
		}
	}
	return s.isEmpty();
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
	return (symbol == '(' || symbol == '[' || symbol == '{');
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