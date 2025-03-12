
#include "Weapon.hpp"

std::string Weapon::getType(void) const
{
	return string;
}

void	Weapon::setType(std::string new_str)
{
	string = new_str;
}

