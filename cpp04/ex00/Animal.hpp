
#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <iostream>
#include <string>


class Animal
{
protected:
	std::string name;
public:
	Animal(std::string name);
	~Animal();
	void makeSound(void);
};

#endif
