#ifndef COMPUTOR_HPP
#define COMPUTOR_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Parser.hpp"
#include "Lexer.hpp"
#include "DType.hpp"
#include "Real.hpp"

class Computor
{
private:
	Parser parser;
	Lexer lexer;

	std::vector<std::string> tokens;
	std::map<std::string, DType> variables;
public:
	Computor(/* args */);
	~Computor();

	void process(std::string input);
};

#endif
