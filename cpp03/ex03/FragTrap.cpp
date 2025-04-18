
#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	health = 100;
	energy = 100;
	att = 30;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " says: High five, guys!\n";
}

FragTrap::~FragTrap() {}
