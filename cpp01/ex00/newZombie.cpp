
#include "Zombie.hpp"

std::string Zombie::get_name(void)
{
	return (name);
}


void	Zombie::announce( void )
{
	std::cout << get_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::newZombie(std::string input)
{
	Zombie new_z;

	name = input;
	std::cout << input << std::endl;
	return (&new_z);
}

