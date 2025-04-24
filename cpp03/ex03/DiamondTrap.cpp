
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name1) : ClapTrap(name1 + "_clap_name"), ScavTrap(name1), 
		FragTrap(name1),
		name(name1)
{
	health = FragTrap::health;
	energy = ScavTrap::energy;
	att = FragTrap::att;
	std::cout << "DiamondTrap Constructer named " << name1 << " called!" << std::endl; 
}

DiamondTrap::~DiamondTrap() 
{
	std::cout << "Destructer DiamondTrap called!\n";
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}

void	DiamondTrap::attack(std::string target)
{
	ScavTrap::attack(target);
}