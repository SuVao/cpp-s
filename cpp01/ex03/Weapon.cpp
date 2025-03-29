
#include "Weapon.hpp"

Weapon::Weapon(const std::string& string) : m_string(string){}

Weapon::~Weapon(){};

const std::string& Weapon::getType(void) const
{
	return m_string;
}

void	Weapon::setType(std::string new_str)
{
	m_string = new_str;
}

