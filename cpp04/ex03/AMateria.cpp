
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type1) : type(type1)
{
    std::cout << "AMateria constructor called!\n";
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

void   AMateria::use(ICharacter &target)
{
    
}