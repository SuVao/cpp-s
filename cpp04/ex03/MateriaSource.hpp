
#pragma once

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "Interfaces.hpp"
#include "Character.hpp"
#include <string>
#include <iostream>


class MateriaSource : public IMateriaSource
{
private:
    AMateria* materiaStore[4];
public:
    MateriaSource();
    ~MateriaSource();
    void    learnMateria(AMateria* materia);
    AMateria* createMateria(std::string const & type);
	MateriaSource& operator=(const MateriaSource& other);
	MateriaSource(const MateriaSource& other);
};

#endif