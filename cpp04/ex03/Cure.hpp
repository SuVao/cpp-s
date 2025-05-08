
#pragma once

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    protected:
        std::string type;
    public:
        Cure();
        Cure(const Cure &copy);
        Cure &operator=(const Cure &copy);
        virtual ~Cure();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif