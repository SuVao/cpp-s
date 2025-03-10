#include "Zombie.hpp"

Zombie::Zombie(std::string input)
{
    name = input;
}

Zombie::~Zombie(void)
{
    std::cout << name << " foi destruído!" << std::endl;
}

std::string Zombie::get_name(void)
{
	return (name);
}

void	Zombie::announce( void )
{
	std::cout << get_name() << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name)
{
	Zombie *new_z = new Zombie(name);
	return (new_z);
}
