
#pragma once

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

//#include "ICharacter.hpp"
#include <string>
#include <iostream>

class AMateria
{
protected:
	std::string type;
public:
	AMateria(std::string const & type1);
	AMateria(const AMateria &copy);
	AMateria &operator=(const AMateria &copy);
	virtual ~AMateria();
	virtual std::string const & getType() const; //Returns the materia type
	virtual AMateria *clone() const = 0; //Returns a new instance of the same type
	virtual void use(ICharacter &target); //Uses the materia on the target character
};


#endif