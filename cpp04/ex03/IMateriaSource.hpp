
#pragma once

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

class IMateriaSource 
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
private:
    AMateria* materiaStore[4];
public:
    MateriaSource();
    void    learnMateria(AMateria* materia);
    AMateria* createMateria(std::string const & type);
};

#endif