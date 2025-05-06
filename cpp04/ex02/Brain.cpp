
#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "Empty idea.\n";
	std::cout << "Brain constructor called!\n";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; ++i)
        this->ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor called\n";
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
        {
            this->ideas[i] = other.ideas[i];
        }
	}
	return *this;
}

void Brain::setIdea(unsigned int n,const std::string& new_idea)
{
	if (n >= 100)
	{
		std::cout << "Wrong Index number of ideas!\n";
		return ;
	}
	ideas[n] = new_idea;
}

std::string Brain::getIdea(unsigned int n) const
{
	return (ideas[n]);
}
