
#pragma once

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : virtual public AMateria
{
public:
    Cure();
    virtual ~Cure();
	Cure& operator=(const AMateria& copy);
	AMateria* clone() const;
};

#endif