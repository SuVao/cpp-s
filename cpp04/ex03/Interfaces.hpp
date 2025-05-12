
#pragma once

#ifndef INTERFACES_HPP
#define INTERFACES_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class AMateria;

class IMateriaSource 
{
public:
	IMateriaSource();
    virtual ~IMateriaSource();
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif