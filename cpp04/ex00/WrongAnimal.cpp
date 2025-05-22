
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal::WrongAnimal(const std::string& type1) : type(type1)
{
	std::cout << "Copy assigment WrongAnimal called\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "I'm the WrongAnimal\n";
}

std::string WrongAnimal::getType() const
{
	return type;
}