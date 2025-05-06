#pragma once

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
    Brain* _brain;
public:
    Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	void	makeSound() const;
	~Dog();
	std::string getIdea_d(unsigned int n) const ;
	void setIdea_d(unsigned int n, const std::string& new_idea);

};

#endif
