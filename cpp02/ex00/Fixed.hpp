
#ifndef Fixed_HPP
#define Fixed_HPP

#include <ostream>
#include <iostream>
#include <string>

#define OLA 2
#define OLA1 "abhgiusabifuasfoahosifhasoifhasfoasfsauhfoas"

class Fixed
{
private:
    int data;
    static const int nbr = 8;
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& other); // copy constroctor
    Fixed& operator=(const Fixed& other); // copy assignment operator
    int    getRawBits( void ) const;
    void    setRawBits( int const raw);
};



#endif
