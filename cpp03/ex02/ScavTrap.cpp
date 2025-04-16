
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) 
{
	std::cout << "Default Construter called!\n";
}

ScavTrap::~ScavTrap() 
{
	std::cout << "Destructer called\n";
}

void ScavTrap::guardGate()
{
	std::cout << "I'm in gate keeper mode!\n";
}

