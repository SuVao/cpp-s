
#include "HumanB.hpp"

		
HumanB::HumanB(std::string name1)
{
	name = name1;
	weapon = NULL;
}

void HumanB::attack() const
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else 
		std::cout << name << " attacks with bare hands" << std::endl; 
}

void HumanB::setWeapon(Weapon& weapon1)
{
	weapon = &weapon1;
}