
#pragma once

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
private:
	std::string type;
public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const std::string& type1);
	std::string getType() const;
	void makeSound() const;
};

#endif