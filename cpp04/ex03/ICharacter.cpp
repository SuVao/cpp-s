#include "ICharacter.hpp"

ICharacter::~ICharacter() 
{
    std::cout << "ICharacter destructor called!\n";
}

std::string const & Character::getName() const
{
    return name;
}

void    Character::equip(AMateria* m)
{
    int i = 0;
    for(int i = 0; i < 4; i++)
        if (inventory[i] == NULL)
            inventory[i] = m;
}