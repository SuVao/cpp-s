
#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("pedro"), b("paula");

	a.attack("paula");
	b.takeDamage(5);
	b.attack("pedro");
	a.takeDamage(5);
	a.beRepaired(10);
	a.attack("paula");
	b.takeDamage(5);
	b.takeDamage(5);

}