
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name1) : name(name1), health(100), energy(50), att(20)
{
	std::cout << "Dafault constructer called!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructer called!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (health == 0)
	{
		std::cout << "ClapTrap is dead\n";
		return;
	}
	if (energy > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " \
				  << att << " points of damage!\n";
		energy--;
	}
	else
		std::cout << "ClapTrap don't have energy!";
	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (health == 0)
	{
		std::cout << "ClapTrap is dead\n";
		return;
	}
	health -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage. Health is now " << health << ".\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (health == 0)
	{
		std::cout << "ClapTrap is dead\n";
		return;
	}
	if (health > 0 && energy > 0)
	{
		std::cout << "ClapTrap " << name << " repairs itself for "
				  << amount << " points. Health is now " << health << ".\n";
		health += amount;
		energy--;
	}
	else
		std::cout << "ClapTrap " << name << " can't repair itself. No energy.\n";
}

