
#include "../inc/Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

AForm* createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* createShrubbery(const std::string& target) 
{
	return new ShrubberyCreationForm(target);
}

AForm* createPresidential(const std::string& target) 
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& form, const std::string& target)
{
	std::string formNames[3] = { "robotomy request", "shrubberycreation form", "presidentialpardon form" };

	AForm* (*creators[3])(const std::string&) = {
		&createRobotomy,
		&createShrubbery,
		&createPresidential,
	};

	for (int i = 0; i < 3; ++i)
	{
		if (form == formNames[i])
		{
			std::cout << "Intern creates " << form << std::endl;
			return creators[i](target);
		}
	}

	throw TheFormDontExist();
}

const char* Intern::TheFormDontExist::what() const throw()
{
	return "This Form doesn't exist!\n";
}