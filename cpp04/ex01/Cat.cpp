
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Constructor called!\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	_brain = new Brain(*other._brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!\n";
	if (_brain)
		delete _brain;
}

void	Cat::makeSound() const
{
	std::cout << "Cats dont bark!\n";
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		if (_brain)
			 delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}