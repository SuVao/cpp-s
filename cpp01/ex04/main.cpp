
#include "sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
	    std::cerr << "Invalid number of arguments!" << std::endl;
		std::cout << "";
		std::getline(line, std::cin);
		return 1;
	}
	s_and_replace(av[1], av[2], av[3]);
	return (0);
}
