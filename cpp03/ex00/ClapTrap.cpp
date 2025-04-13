
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name1) : health(10), energy(10), att(0), name(name1) 
{
	std::cout << "eafault constrocter called!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destrocter called!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{

}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ( health < 0)
	{
		throw "is dead\n";
		exit (-1);
	}

}

void ClapTrap::beRepaired(unsigned int amount)
{

}

