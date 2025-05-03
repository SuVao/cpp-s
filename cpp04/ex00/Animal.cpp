

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Default Animal constructor called!\n";
}

Animal::Animal(const std::string& type1) : type(type1)
{
	std::cout << "Default constructor called!\n";
}

Animal& Animal::operator=(const Animal& )
{
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!\n";
}


std::string Animal::getType() const
{
	return type;
}

void	Animal::makeSound() const
{
		std::cout << "Im here!\n";
}

std::ostream& operator<<(std::ostream& os, const Animal& t)
{
	os << t.getType();
	return os;
}