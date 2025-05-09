#pragma once

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain* _brain;
public:
	Cat();
	~Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	void	makeSound() const;
	std::string getIdea_c(unsigned int n) const;
	void setIdea_c(unsigned int n, const std::string& new_idea);

};

#endif
