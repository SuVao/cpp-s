
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Zombie {
	public:
	Zombie();
	Zombie(std::string name);

	void	announce( void );
	std::string get_name(void);
	private:
	std::string	name;
};

Zombie* zombieHorde( int N, std::string name );
Zombie* newZombie( std::string name );

#endif
