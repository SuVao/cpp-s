
#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	_brain = new Brain;
	std::cout << "Cat Constructor called!\n";
}

Cat::Cat(const Cat& other) : AAnimal(other)
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
	std::cout << "Miau!\n";
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		if (_brain)
			 delete _brain;
		_brain = new Brain(*other._brain); //getideias for copy
	}
	return *this;
}

std::string Cat::getIdea_c(unsigned int n) const 
{
    if (_brain && n < 100)
        return _brain->getIdea(n);
    return "";
}

void Cat::setIdea_c(unsigned int n, const std::string& new_idea)
{
    if (_brain && n < 100)
        _brain->setIdea(n, new_idea);
}