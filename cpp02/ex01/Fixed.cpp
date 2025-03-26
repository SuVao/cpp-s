#include "Fixed.hpp"

Fixed::Fixed() : data(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : data(other.data)
{
    std::cout << "Copy constructor called" << std::endl;
    other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->data = other.getRawBits();
	}
    return *this;
}

int    Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called!" << std::endl;
    return data;
}

void    Fixed::setRawBits( int const raw)
{
    std::cout << "setRawBits member function called!" << std::endl;
    data = raw;
}
