
#include "Zombie.hpp"

Zombie::Zombie(std::string input)
{
    name = input;
}

Zombie::~Zombie(void)
{
    std::cout << name << " was destroyed!" << std::endl;
}

std::string Zombie::get_name(void)
{
	return (name);
}

void	Zombie::announce( void )
{
	std::cout << get_name() << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
