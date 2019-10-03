#include <iostream>
#include <string>
#include "Computor.hpp"

int	main(void)
{
	std::string input;
	bool quit = false;
	Computor computor;

	while (!quit)
	{
		std::getline(std::cin, input);
		if (input == "q")
		{
			quit = true;
		} else
		{
			computor.process(input);
		}
		
	}
	return (0);
}