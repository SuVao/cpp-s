
#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

Ice& Ice::operator=(const AMateria& copy)
{
	if (this != &copy)
		*this = copy;
	if (copy.getType() == "ice")
		this->type = copy.getType();
	return *this;
}