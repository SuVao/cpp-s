
#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "Default AAnimal constructor called!\n";
}

AAnimal::AAnimal(const std::string& type1) : type(type1)
{
	std::cout << "Default constructor called!\n";
}

AAAnimal& AAnimal::operator=(const AAnimal& )
{
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called!\n";
}


std::string AAnimal::getType() const
{
	return type;
}

void	AAnimal::makeSound() const
{
	std::cout << "Normaly only Animal don't have a especific sound\n";
}

std::ostream& operator<<(std::ostream& os, const AAnimal& t)
{
	os << t.getType();
	return os;
}