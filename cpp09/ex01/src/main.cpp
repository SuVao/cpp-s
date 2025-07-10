
#include "../inc/RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Invalid number of arguments\n";
		return 1;
	}
	try
	{
		RPN a((std::string(av[1])));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}