
#ifndef Fixed_HPP
#define Fixed_HPP

#include <ostream>
#include <iostream>
#include <string>

class Fixed
{
private:
    int data;
    static const int nbr;
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& other); // copy constroctor
    Fixed& operator=(const Fixed& other); // copy assignment operator
    int    getRawBits( void ) const;
    void    setRawBits( int const raw);
};



#endif
