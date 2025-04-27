

#include "Animal.hpp"

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal Constructor called!\n";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!\n";
}

void	Animal::makeSound()
{
	std::cout << "Im here!\n";
}