
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"



class Weapon {
	private:
	std::string string;
	
	public:
	std::string getType(void) const;
	void setType(std::string new_str);
	
};



#endif