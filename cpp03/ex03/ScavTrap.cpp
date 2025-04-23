
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "Default Constructer ScavTrap called!\n";
	health = 100;
	energy = 100;
	att = 30;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "Destructer ScavTrap called\n";
}

void ScavTrap::guardGate()
{
	std::cout << "I'm in gate keeper mode!\n";
}

