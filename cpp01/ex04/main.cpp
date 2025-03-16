
#include "sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
		return -1;
	std::ifstream file(av[1]);
	if (!file)
	{
		std::cout << "file not found\n";
		return -1;
	}
	
}

