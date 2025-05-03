

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	_brain = new Brain;
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

std::string Dog::getIdea_d(unsigned int n) const 
{
    if (_brain && n < 100)
        return _brain->getIdea(n);
    return "";
}

void Dog::setIdea_d(unsigned int n, const std::string& new_idea)
{
    if (_brain && n < 100)
        _brain->setIdea(n, new_idea);
}