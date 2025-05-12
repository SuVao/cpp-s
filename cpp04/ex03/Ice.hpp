
#pragma once

#ifndef ICE_HPP
#define ICE_HPP

#include "Character.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const std::string& type);
    virtual ~Ice();
	AMateria* clone() const;
 	Ice& operator=(const AMateria& copy);

};

#endif