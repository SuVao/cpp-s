
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Constructor called!\n";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!\n";
}

void	Cat::makeSound() const
{
	std::cout << "Cats dont bark!\n";
}