
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name1) : ClapTrap(name1 + "_clap_name"), ScavTrap(name1), 
		FragTrap(name1),
		name(name1)
{
	health = FragTrap::health;
	energy = ScavTrap::energy;
	att = FragTrap::att;
	std::cout << "DiamondTrap Constructer named " << name1 << " was called!" << std::endl; 
}

DiamondTrap::~DiamondTrap() {}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}

void	DiamondTrap::Attack(std::string target)
{
	ScavTrap::attack(target);
}