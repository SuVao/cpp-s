
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"


class HumanB
{
	private:
	std::string name;
	Weapon* weapon;
	public:
	HumanB(std::string name1);
	void attack() const;
	void setWeapon(Weapon& weapon);
};


#endif
