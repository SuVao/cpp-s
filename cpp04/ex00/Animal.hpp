
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
	Animal(std::string type);
	~Animal();
	void makeSound(void);
	void getType();
};

#endif
