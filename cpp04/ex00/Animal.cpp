

#include "Animal.hpp"

Animal::Animal(std::string name) : name(name)
{
	std::cout << "Default Constructer called!\n";
}

void	Animal::makeSound()
{
	std::cout << "Im here!\n";
}