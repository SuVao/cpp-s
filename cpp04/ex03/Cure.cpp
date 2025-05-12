
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure(){}

AMateria* Cure::clone() const 
{
    return new Cure(*this);
}

Cure& Cure::operator=(const AMateria& copy)
{
	if (this != &copy)
		*this = copy;
	if (copy.getType() == "cure")
		this->type = copy.getType();
	return *this;
}
