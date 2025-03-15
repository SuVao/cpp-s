
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
	private:
	std::string string;
	public:
	Weapon(std::string string) : string(string){};
	~Weapon();
	const std::string& getType(void) const;
	void setType(std::string new_str);

};



#endif