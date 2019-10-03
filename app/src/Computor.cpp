#include "Computor.hpp"

Computor::Computor(/* args */)
{
}

Computor::~Computor()
{
}

void Computor::process(std::string input)
{
	try
	{
		tokens = lexer.lex(input);
		/**/for (auto cal : tokens) {std::cout << cal << std::endl;}
		/**/switch (parser.evalTokens(tokens))
		{
		case invalid:
			std::cout << "invalid" << std::endl;
			break;
		case assignment:
			std::cout << "assignment" << std::endl;
			break;
		case evaluation:
			std::cout << "evaluation" << std::endl;
			break;
		
		default:
			break;
		}
		// Real real1, real2, real3;
		// std::vector<double> val1, val2;
		// val1.push_back(2);
		// val2.push_back(0);
		// real1.setValues(val1);
		// real2.setValues(val2);
		// std::cout << real1.toStr() + " + " + real2.toStr() << std::endl;
		// real3 = real1 + real2;
		// std::cout << real3.toStr() << std::endl;
		// std::cout << real1.toStr() + " - " + real2.toStr() << std::endl;
		// real3 = real1 - real2;
		// std::cout << real3.toStr() << std::endl;
		// std::cout << real1.toStr() + " * " + real2.toStr() << std::endl;
		// real3 = real1 * real2;
		// std::cout << real3.toStr() << std::endl;
		// std::cout << real1.toStr() + " / " + real2.toStr() << std::endl;
		// real3 = real1 / real2;
		// std::cout << real3.toStr() << std::endl;
		// std::cout << real1.toStr() + " ^ " + real2.toStr() << std::endl;
		// real3 = real1 ^ real2;
		// std::cout << real3.toStr() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
