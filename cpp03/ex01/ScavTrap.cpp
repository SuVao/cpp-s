
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) 
{
	std::cout << "Constructer ScavTrap called!\n";
	health = 100;
	energy = 50;
	att = 20;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "Destructer ScavTrap called\n";
}

void ScavTrap::guardGate()
{
	std::cout << "I'm in gate keeper mode!\n";
}

