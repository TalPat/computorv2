#include "Parser.hpp"

Parser::Parser(/* args */)
{
}

Parser::~Parser()
{
}

tokenEval Parser::evalTokens(std::vector<std::string> tokens)
{
	if (tokens.size() == 0){
		return (empty);
	}
	else if (tokens[tokens.size() - 1] == "?")
	{
		//Handle evaluation
		return (evaluation);
	}
	else
	{
		//testing evaluations - remove
		// std::cout << "token size: " << tokens.size() << std::endl;
		// std::cout << "token 0 isVar: " << isVar(tokens[0]) << std::endl;
		// std::cout << "token 1 is: " << tokens[1] << std::endl;
		// validEq(tokens, 2, tokens.size() - 1);



		//Handle assignment
		//curently not handling functions
		if (tokens.size() < 3 ||
				!isVar(tokens[0]) ||
				tokens[1] != "=" ||
				!validEq(tokens, 2, tokens.size() - 1))
			return (invalid);
		return (assignment);
	}
}

bool Parser::isAlNum(std::string str)
{
	for (char c : str)
	{
		if (!isalnum(c))
			return (false);
	}
	return (true);
}

bool Parser::isNumeric(std::string str)
{
	bool decimal = false;

	for (char c : str)
	{
		if (!isdigit(c) && c != '.')
			return (false);
		if (c == '.' && decimal)
			return (false);
		if (c == '.')
			decimal = true;
	}
	return (true);
}

bool Parser::isVar(std::string str)
{
	if (/*!isalpha(str[0]) ||*/ !isAlNum(str))
	{
		return (false);
	}
	return (true);
}

bool Parser::isOperator(std::string str)
{
	std::string operators = "+-*/^";
	if (str.size() > 1 || operators.find(str[0]) == std::string::npos)
	{
		return (false);
	}
	return (true);
}

bool Parser::isBracket(std::string str)
{
	std::string operators = "()[]";
	if (str.size() > 1 || operators.find(str[0]) == std::string::npos)
	{
		return (false);
	}
	return (true);
}

bool Parser::validEq(std::vector<std::string> tokens, unsigned int startIdx, unsigned int endIdx)
{
	if (!evalBrackets(tokens, startIdx, endIdx))
	{
		/**/std::cout << "bad brackets" << std::endl;
		return (false);
	}
	for (size_t i = startIdx; i <= endIdx; i++)
	{
	//***/std::cout << tokens[i] << i << std::endl;
		if (isVar(tokens[i]) &&
				i != endIdx &&
				!isOperator(tokens[i + 1]) &&
				!isBracket(tokens[i + 1]))
		{
			/**/std::cout << "bad var" << std::endl;
			return (false);
		}
		else if (isNumeric(tokens[i]) &&
						 i != endIdx &&
						 !isOperator(tokens[i + 1]) &&
						 !isBracket(tokens[i + 1]))
		{
			/**/std::cout << "bad numeric" << std::endl;
			return (false);
		}
		else if ((isOperator(tokens[i]) &&
						 i == endIdx) ||
						 (isOperator(tokens[i]) &&
						 !isNumeric(tokens[i + 1]) &&
						 !isBracket(tokens[i + 1]) &&
						 !isVar(tokens[i + 1])))
		{
			//testing
			// if (i != endIdx)
			// {
			// 	std::cout << "next numeric: " << isNumeric(tokens[i + 1]) << " next bracket: " << isBracket(tokens[i + 1]) << "next variable: " << isVar(tokens[i + 1]) << std::endl;
			// }
			/**/std::cout << "bad operator" << std::endl;
			return (false);
		}
		else if ((tokens[i] == "(" &&
						 i == endIdx) ||
						 (tokens[i] == "(" &&
						 !isNumeric(tokens[i + 1]) &&
						 !isOperator(tokens[i + 1]) &&
						 !isVar(tokens[i + 1]) &&
						 tokens[i+1] != "(" &&
						 tokens[i+1] != "["))
		{
			/**/std::cout << "bad (" << std::endl;
			return (false);
		}
		else if (tokens[i] == ")" &&
						 i != endIdx &&
						 !isOperator(tokens[i + 1]))
		{
			/**/std::cout << "bad )" << std::endl;
			return (false);
		}	
	}
	return (true);
}

bool Parser::evalBrackets(std::vector<std::string> tokens, unsigned int startIdx, unsigned int endIdx)
{
	std::vector<std::string> brackets;
	for (size_t i = startIdx; i <= endIdx; i++)
	{
		if (tokens[i] == "(" || tokens[i] == "[")
			brackets.push_back(tokens[i]);
		else if (tokens[i] == ")")
		{
			if (brackets.size() >= 1 && brackets[brackets.size() - 1] == "(")
				brackets.pop_back();
			else
				return false;
		}
		else if (tokens[i] == "]")
		{
			if (brackets.size() >= 1 && brackets[brackets.size() - 1] == "[")
				brackets.pop_back();
			else
				return false;
		}
	}
	if (brackets.size() != 0)
	{
		for (auto str : brackets)
		{
			std::cout << str << std::endl;
		}
		return false;
	}
	else
		return (true);
}
