
#include "Weapon.hpp"

//Weapon::Weapon(std::string string) : string(string){};
//
Weapon::~Weapon(){};

const std::string& Weapon::getType(void) const
{
	return string;
}

void	Weapon::setType(std::string new_str)
{
	string = new_str;
}

