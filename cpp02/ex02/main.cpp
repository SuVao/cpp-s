
#include "Fixed.hpp"
#include <exception>

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	//std::cout << Fixed::min( a, b ) << std::endl;

/* 	float res;

	res = 2.2 * 5.5;

	std::cout << res << std::endl;

	Fixed a( Fixed( 2.2f ) * Fixed( 5.5f ));

	std::cout << a << std::endl; */

	return 0;
}