
#include "AMateria.hpp"

AMateria::AMateria(std::string const & type1) : type(type1) {}

AMateria::AMateria(const AMateria& other) : type(other.type) {}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& copy)
{
    type = copy.type;
    return *this;
}

void   AMateria::use(ICharacter &target)
{
    if (getType() == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << "*\n";
	if (getType() == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *\n"; 
}
std::string const & AMateria::getType() const
{
	return (type);
}