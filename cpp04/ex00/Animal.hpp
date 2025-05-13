
#pragma once

#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const std::string& type);
	virtual ~Animal();
	virtual void makeSound(void) const;
	virtual std::string getType() const;
	Animal& operator=(const Animal& );
};

std::ostream& operator<<(std::ostream os, const Animal& Animal);


#endif
