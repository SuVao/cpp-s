
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(const std::string& type1) : type(type1)
{
    std::cout << "Default constructor called!\n";
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
    std::cout << "AMateria copy constructor called!\n";
}

AMateria::~AMateria()
{
    std::cout << "Default AMateria destructor called\n";
}

AMateria& AMateria::operator=(const AMateria& copy)
{
    type = copy.type;
    return *this;
}

const std::string& AMateria::getType() const
{
    return type;
}
