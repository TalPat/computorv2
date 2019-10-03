#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <string>
#include <iostream>

enum tokenEval
{
	assignment,
	evaluation,
	invalid,
	empty
};

class Parser
{
private:
	/* data */
	bool isAlNum(std::string str);
	bool isNumeric(std::string str);
	bool isVar(std::string str);
	bool isOperator(std::string str);
	bool isBracket(std::string str);
	bool validEq(std::vector<std::string> tokens, unsigned int startIdx, unsigned int endIdx);
	bool evalBrackets(std::vector<std::string> tokens, unsigned int startIdx, unsigned int endIdx);
public:
	Parser(/* args */);
	~Parser();

	tokenEval evalTokens(std::vector<std::string> tokens);
};

#endif
