#include "Character.hpp"

std::string const & Character::getName() const
{
    return name;
}

void    Character::equip(AMateria* m)
{
    for(int i = 0; i < 4; i++)
        if (inventory[i] == NULL)
		{
            inventory[i] = m->clone();
			delete m;
			return ;
		}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		std::cout << "Invalid index!\n";
	for (int i = 0; i < 4; i++)
		if (i == idx && inventory[i])
		{
			AMateria* tmp;
			tmp = inventory[i];
			inventory[i] = NULL;
			delete tmp;
			std::cout << "the slot number " << i << " is empty now.\n"; 
			return ;
		}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		std::cout << "Invalid index!\n";
	for (int i = 0; i < 4; i++)
		if (i == idx && inventory[i])
		{
			inventory[i]->use(target);
			return ;
		}
}
Character::Character(const std::string& name1) : name(name1)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::~Character()
{
	for (int i = 0;i < 4;i++)
	{
		if (inventory[i])
			delete inventory[i];
		inventory[i] = NULL;
	}
}

Character::Character(const Character& other) 
{
	this->name = other.name;
	for (int i = 0; i < 4; ++i) {
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone(); // faz deep copy
		else
			this->inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other) 
{
    if (this == &other)
        return *this;
    this->name = other.name;
	for (int i = 0; i < 4; ++i)
	{
		delete this->inventory[i];
		this->inventory[i] = NULL;
	}
	for (int i = 0; i < 4; ++i) 
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone(); // deep copy
	}
return *this;
}
