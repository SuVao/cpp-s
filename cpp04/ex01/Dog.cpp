

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Constructor called\n";
}

Dog::~Dog()
{
	if (_brain)
		delete _brain;
	std::cout << "Dog destructor called!\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	_brain = new Brain(*other._brain);
}


Dog& Dog::operator=(const Dog& other)
{
	if (_brain)
		delete _brain;
	_brain = new Brain(*other._brain);
	return *this;	
}

void Dog::makeSound() const
{
	std::cout << "au au!\n";
}