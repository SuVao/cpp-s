
#include "Fixed.hpp"

Fixed::Fixed() : data(0)
{
    std::cout << "Default constroctor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : data(other.data)
{
    std::cout << "Copy constroctor called" << std::endl;
    other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy Assignment Operator called" << std::endl;
    this->data = other.data;
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
