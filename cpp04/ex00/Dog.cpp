

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Constructor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!\n";
}

void Dog::makeSound() const
{
	std::cout << "au au!\n";
}