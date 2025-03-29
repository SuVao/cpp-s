
#include "HumanA.hpp"

HumanA::HumanA(std::string name1, Weapon& weapon1) : name(name1), weapon(weapon1){}

void HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}