#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string input) : name(input) {}

std::string Zombie::get_name(void)
{
	return (name);
}

void	Zombie::announce( void )
{
	std::cout << get_name() << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
