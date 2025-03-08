
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {	
	public:

	std::string get_name(void);
	void randomChump( std::string name );
	
	Zombie* newZombie( std::string name );
	~Zombie(void);
	
	private:
	
	std::string	name;
	void	announce( void );


};

#endif