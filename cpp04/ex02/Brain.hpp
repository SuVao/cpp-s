
#pragma once

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "AAnimal.hpp"

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	virtual ~Brain();
	void setIdea(unsigned int n,const std::string& new_idea);
	std::string getIdea(unsigned int n) const;
};

#endif