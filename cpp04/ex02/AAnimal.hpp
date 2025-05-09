
#pragma once

#ifndef AANIMAL_HPP
#define AANIMAL_HPP


#include <iostream>
#include <string>

class AAnimal
{
protected:
	std::string type;
public:
	AAnimal();
	AAnimal(const std::string& type);
	virtual ~AAnimal();
	void makeSound(void) const;
	virtual std::string getType() const;
	AAnimal& operator=(const AAnimal& );

};

std::ostream& operator<<(std::ostream os, const AAnimal& AAnimal);


#endif
